//
// Created by Hoonyong Park on 6/12/23.
//

#include "task.hpp"

#include <lib/rrc/encode.hpp>
#include <ue/rls/task.hpp>

#include <asn/rrc/ASN_RRC_DL-DCCH-Message.h>
#include <asn/rrc/ASN_RRC_MeasurementReport.h>
#include <asn/rrc/ASN_RRC_MeasurementReport-IEs.h>
#include <asn/rrc/ASN_RRC_MeasResults.h>
#include <asn/rrc/ASN_RRC_MeasResultServMOList.h>
#include <asn/rrc/ASN_RRC_MeasResultServMO.h>
#include <asn/rrc/ASN_RRC_MeasResultNR.h>
#include <asn/rrc/ASN_RRC_MeasResultListNR.h>
#include <asn/rrc/ASN_RRC_PhysCellId.h>
#include <asn/rrc/ASN_RRC_MeasQuantityResults.h>
#include <asn/rrc/ASN_RRC_RSRP-Range.h>
#include <asn/rrc/ASN_RRC_RRCSetupComplete-IEs.h>
#include <asn/rrc/ASN_RRC_RRCSetupComplete.h>
#include <asn/rrc/ASN_RRC_RRCReconfigurationComplete.h>
#include <asn/rrc/ASN_RRC_RRCReconfigurationComplete-IEs.h>
#include <asn/rrc/ASN_RRC_RRCReconfiguration.h>
#include <asn/rrc/ASN_RRC_RRCReconfiguration-IEs.h>
#include <asn/rrc/ASN_RRC_CellGroupConfig.h>
#include <asn/rrc/ASN_RRC_SpCellConfig.h>
#include <asn/rrc/ASN_RRC_ReconfigurationWithSync.h>
#include <asn/rrc/ASN_RRC_ServingCellConfigCommon.h>

namespace nr::ue
{

static long dbm2RsrpRange(double dbm)
{
    long result;

    if (dbm < -156)
        result = 0;
    else if (dbm > -31)
        result = 126;
    else
    {
        result = 156 + (long)dbm;
    }

    return result;

}

static ASN_RRC_UL_DCCH_Message *ConstructMeasurementReport(long measId, int servPCI, double servDbm, UeCellDesc* neighCells, int countNeighCell)
{
    auto *pdu = asn::New<ASN_RRC_UL_DCCH_Message>();
    pdu->message.present = ASN_RRC_UL_DCCH_MessageType_PR_c1;
    pdu->message.choice.c1 = asn::NewFor(pdu->message.choice.c1);
    pdu->message.choice.c1->present = ASN_RRC_UL_DCCH_MessageType__c1_PR_measurementReport;

    auto &measurementReport = pdu->message.choice.c1->choice.measurementReport = asn::New<ASN_RRC_MeasurementReport>();
    measurementReport->criticalExtensions.present = ASN_RRC_MeasurementReport__criticalExtensions_PR_measurementReport;

    auto &measurementReportIEs = measurementReport->criticalExtensions.choice.measurementReport = asn::New<ASN_RRC_MeasurementReport_IEs>();

    auto *servPhyCellId = asn::New<ASN_RRC_PhysCellId_t>();
    *servPhyCellId = servPCI;

    auto *servRsrp = asn::New<ASN_RRC_RSRP_Range_t>();
    *servRsrp = dbm2RsrpRange(servDbm);

    auto *servResultsSSB_Cell = asn::New<ASN_RRC_MeasQuantityResults>();
    servResultsSSB_Cell->rsrp = servRsrp;

    auto *measResultServMo = asn::New<ASN_RRC_MeasResultServMO>();
    measResultServMo->servCellId = 0;
    measResultServMo->measResultServingCell.physCellId = servPhyCellId;
    measResultServMo->measResultServingCell.measResult.cellResults.resultsSSB_Cell = servResultsSSB_Cell;

    measurementReportIEs->measResults.measId = measId;
    asn::SequenceAdd(measurementReportIEs->measResults.measResultServingMOList, measResultServMo);


    auto *measResultNeighCells = measurementReportIEs->measResults.measResultNeighCells = new ASN_RRC_MeasResults::ASN_RRC_MeasResults__measResultNeighCells;
    measResultNeighCells->present = ASN_RRC_MeasResults__measResultNeighCells_PR_measResultListNR;
    auto *measResultListNR = measResultNeighCells->choice.measResultListNR = asn::New<ASN_RRC_MeasResultListNR>();

    for (int i = 0; i < countNeighCell; i++)
    {
        auto *neighPhyCellId = asn::New<ASN_RRC_PhysCellId_t>();
        *neighPhyCellId = (int32_t)neighCells[i].sib1.nci;

        auto *neighRsrp = asn::New<ASN_RRC_RSRP_Range_t>();
        *neighRsrp = dbm2RsrpRange(neighCells[i].dbm);

        auto *neighResultsSSB_Cell = asn::New<ASN_RRC_MeasQuantityResults>();
        neighResultsSSB_Cell->rsrp = neighRsrp;

        auto *measResultNR = asn::New<ASN_RRC_MeasResultNR>();
        measResultNR->physCellId = neighPhyCellId;
        measResultNR->measResult.cellResults.resultsSSB_Cell = neighResultsSSB_Cell;

        asn::SequenceAdd(*measResultListNR, measResultNR);
    }

    return pdu;
}

void UeRrcTask::SendMeasurementReport()
{
    m_logger->debug("Sending MeasurementReport");

    int activeCell = m_base->shCtx.currentCell.get<int>([](auto &item) { return item.cellId; });

    int servPCI = (int32_t)m_cellDesc[activeCell].sib1.nci;

    double servDbm = m_cellDesc[activeCell].dbm;

    auto *neighCell = new UeCellDesc[m_cellDesc.size() - 1];

    int i = 0;
    for (auto &a : m_cellDesc)
    {
        if (a.first != activeCell)
            neighCell[i++] = a.second;
    }

    auto *measurementReport = ConstructMeasurementReport(getMeasId(), servPCI, servDbm, neighCell, i);

    sendRrcMessage(measurementReport);

    asn::Free(asn_DEF_ASN_RRC_UL_DCCH_Message, measurementReport);
    delete neighCell;
}

long UeRrcTask::getMeasId()
{
    long result = measId++;
    if (measId == 64)
        measId = 1;
    return result;
}

void UeRrcTask::receiveRrcReconfiguration(const ASN_RRC_RRCReconfiguration &msg)
{
    m_logger->debug("Receiving Rrc Reconfiguration");

    m_state = ERrcState::RRC_CONNECTED_HANDOVER;

    int tid = msg.rrc_TransactionIdentifier;

    double bestDbm = -999.0;
    long bestPCI = 0;


    for (auto& it : m_cellDesc)
    {
        if(it.second.dbm > bestDbm)
        {
            bestPCI = it.second.sib1.nci;
            bestDbm = it.second.dbm;
        }
    }

    long targetCellID = bestPCI;

    ActiveCellInfo cellInfo{};

    for (auto& it : m_cellDesc)
    {
        if (it.second.sib1.nci == targetCellID)
        {
            cellInfo.cellId = it.first;
            cellInfo.plmn = it.second.sib1.plmn;
            cellInfo.tac = it.second.sib1.tac;
            cellInfo.category = ECellCategory::ACCEPTABLE_CELL;
            break;
        }
    }

    m_base->shCtx.currentCell.set(cellInfo);

    auto w1 = std::make_unique<NmUeRrcToRls>(NmUeRrcToRls::ASSIGN_CURRENT_CELL);
    w1->cellId = cellInfo.cellId;
    w1->cause = rrc::AssignCellCause::RRC_RECONFIGURATION;
    m_base->rlsTask->push(std::move(w1));
}

void UeRrcTask::sendRrcReconfigurationComplete()
{
        auto *rrcReconfigurationComplete = asn::New<ASN_RRC_UL_DCCH_Message>();
        rrcReconfigurationComplete->message.present = ASN_RRC_UL_DCCH_MessageType_PR_c1;
        rrcReconfigurationComplete->message.choice.c1 = asn::NewFor(rrcReconfigurationComplete->message.choice.c1);
        rrcReconfigurationComplete->message.choice.c1->present = ASN_RRC_UL_DCCH_MessageType__c1_PR_rrcReconfigurationComplete;

        auto &reconfigurationComplete = rrcReconfigurationComplete->message.choice.c1->choice.rrcReconfigurationComplete = asn::New<ASN_RRC_RRCReconfigurationComplete>();
        reconfigurationComplete->rrc_TransactionIdentifier = 1;
        reconfigurationComplete->criticalExtensions.present = ASN_RRC_RRCReconfigurationComplete__criticalExtensions_PR_rrcReconfigurationComplete;

        reconfigurationComplete->criticalExtensions.choice.rrcReconfigurationComplete = asn::New<ASN_RRC_RRCReconfigurationComplete_IEs>();

        sendRrcMessage(rrcReconfigurationComplete);
        asn::Free(asn_DEF_ASN_RRC_UL_DCCH_Message, rrcReconfigurationComplete);

        m_state = ERrcState::RRC_CONNECTED;

        m_logger->debug("Sending Rrc Reconfiguration Complete");
}



}
