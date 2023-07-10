//
// Created by Hoonyong Park on 6/13/23.
//

#include "task.hpp"

#include <CU/f1ap/task.hpp>

using namespace std;

namespace nr::CU
{

void CURrcTask::receiveMeasurementReport(int duId, int gNB_DU_ID, std::string data)
{
    // MeasurementReport|ueId|servPCI|servDbm|countNeighCell|neighPCI|neighDbm|...
    auto msg = split(data, '|');

    auto DU_UE_Id = stoi(msg.at(1));
    auto *ue = findUeByGNB_DU_UE_ID(gNB_DU_ID, DU_UE_Id);

    long servPCI = stoi(msg.at(2));
    long servDbm = stoi(msg.at(3));

    int countNeighCell = stoi(msg.at(4));

    long bestNeighPCI = 0;
    long bestNeighDbm = 0;

    for (int i = 0; i < countNeighCell; i++)
    {
        long neighPCI = stoi(msg.at(5 + (i*2)));
        long neighDbm = stoi(msg.at(6 + (i*2)));

        if (neighDbm >= bestNeighDbm)
        {
            bestNeighDbm = neighDbm;
            bestNeighPCI = neighPCI;
        }
    }

    if ((bestNeighDbm - servDbm) >= 3)
    {
        if (ue->state == ERrcState::RRC_CONNECTED)
            TriggerInterDuHandover(duId, ue->ueId,  bestNeighPCI);
    }
}

void CURrcTask::TriggerInterDuHandover(int duId, int ueId, long targetPCI)
{
    auto *ue = findUe(ueId);

    ue->state = ERrcState::RRC_CONNECTED_HANDOVER;

    auto w = std::make_unique<NmCURrcToF1ap>(NmCURrcToF1ap::UE_CONTEXT_SETUP_REQUEST);
    w->duId = duId;
    w->ueId = ueId;
    w->GNB_DU_UE_ID = ue->GNB_DU_UE_ID;
    w->sourcePCI = ue->gNB_DU_ID;
    w->targetPCI = targetPCI;
    m_base->f1apTask->push(std::move(w));

    m_logger->info("Handover Triggerd About UE[%d] From PCI[%d] To PCI[%d]", ueId, ue->gNB_DU_ID, targetPCI);
}

void CURrcTask::receiveRrcReconfigurationComplete(int duId, int gNB_DU_ID, std::string data)
{
    auto msg = split(data, '|');

    int GNB_DU_UE_ID = stoi(msg.at(1));

    int64_t sti = stoll(msg.at(2));

    auto *ue = findUeBySti(sti);

    int privDU_ID = ue->gNB_DU_ID;
    int privGNB_DU_UE_ID = ue->GNB_DU_UE_ID;

    ue->gNB_DU_ID = gNB_DU_ID;
    ue->GNB_DU_UE_ID = GNB_DU_UE_ID;

    ue->state = ERrcState::RRC_CONNECTED;

    m_logger->info("A handover procedure is done : UE[%d] SourcePCI[%d] -> TargetPCI[%d]", ue->ueId, privDU_ID, ue->gNB_DU_ID);

    auto w = std::make_unique<NmCURrcToF1ap>(NmCURrcToF1ap::UE_CONTEXT_RELEASE_COMMAND);
    w->duId = privDU_ID;
    w->GNB_DU_UE_ID = privGNB_DU_UE_ID;
    m_base->f1apTask->push(std::move(w));
}

}