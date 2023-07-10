//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "task.hpp"

#include <lib/rrc/encode.hpp>
#include <ue/nas/task.hpp>
#include <ue/nts.hpp>
#include <utils/random.hpp>

#include <asn/rrc/ASN_RRC_RRCSetup-IEs.h>
#include <asn/rrc/ASN_RRC_RRCSetup.h>
#include <asn/rrc/ASN_RRC_RRCSetupComplete-IEs.h>
#include <asn/rrc/ASN_RRC_RRCSetupComplete.h>
#include <asn/rrc/ASN_RRC_RRCSetupRequest-IEs.h>
#include <asn/rrc/ASN_RRC_RRCSetupRequest.h>
#include <asn/rrc/ASN_RRC_UECapabilityEnquiry.h>
#include <asn/rrc/ASN_RRC_UECapabilityEnquiry-IEs.h>
#include <asn/rrc/ASN_RRC_UECapabilityInformation-IEs.h>
#include <asn/rrc/ASN_RRC_UECapabilityInformation.h>
#include <asn/rrc/ASN_RRC_UE-CapabilityRAT-Container.h>
#include <asn/rrc/ASN_RRC_UE-CapabilityRAT-ContainerList.h>
#include <asn/rrc/ASN_RRC_UE-NR-Capability.h>
#include <asn/rrc/ASN_RRC_BandNR.h>
#include <asn/rrc/ASN_RRC_FreqBandList.h>
#include <asn/rrc/ASN_RRC_FreqBandInformationNR.h>
#include <asn/rrc/ASN_RRC_FreqBandInformation.h>
#include <asn/rrc/ASN_RRC_AggregatedBandwidth.h>


namespace nr::ue
{

static ASN_RRC_UL_CCCH_Message *ConstructSetupRequest(ASN_RRC_InitialUE_Identity_t initialUeId,
                                                      ASN_RRC_EstablishmentCause_t establishmentCause)
{
    auto *pdu = asn::New<ASN_RRC_UL_CCCH_Message>();
    pdu->message.present = ASN_RRC_UL_CCCH_MessageType_PR_c1;
    pdu->message.choice.c1 = asn::NewFor(pdu->message.choice.c1);
    pdu->message.choice.c1->present = ASN_RRC_UL_CCCH_MessageType__c1_PR_rrcSetupRequest;

    auto &r = pdu->message.choice.c1->choice.rrcSetupRequest = asn::New<ASN_RRC_RRCSetupRequest>();
    asn::DeepCopy(asn_DEF_ASN_RRC_InitialUE_Identity, initialUeId, &r->rrcSetupRequest.ue_Identity);
    r->rrcSetupRequest.establishmentCause = establishmentCause;
    asn::SetSpareBits<1>(r->rrcSetupRequest.spare);

    return pdu;
}

void UeRrcTask::startConnectionEstablishment()
{
    /* Check the protocol state */
    if (m_state != ERrcState::RRC_IDLE)
    {
        m_logger->err("RRC establishment could not start, UE not in RRC-IDLE state");
        return;
    }

    /* Check the current cell */
    int activeCell = m_base->shCtx.currentCell.get<int>([](auto &item) { return item.cellId; });
    if (activeCell == 0)
    {
        m_logger->err("RRC establishment could not start, no active cell");
        return;
    }

    /* Handle Initial UE Identity (S-TMSI or 39-bit random value) */
    std::optional<GutiMobileIdentity> gutiOrTmsi = m_base->shCtx.providedGuti.get();
    if (!gutiOrTmsi)
        gutiOrTmsi = m_base->shCtx.providedTmsi.get();

    if (gutiOrTmsi)
    {
        m_initialId.present = ASN_RRC_InitialUE_Identity_PR_ng_5G_S_TMSI_Part1;
        asn::SetBitStringLong<39>(static_cast<int64_t>(gutiOrTmsi->tmsi) |
                                      (static_cast<int64_t>(gutiOrTmsi->amfPointer & 0b1111111) << 32ull),
                                  m_initialId.choice.ng_5G_S_TMSI_Part1);
    }
    else
    {
        m_initialId.present = ASN_RRC_InitialUE_Identity_PR_randomValue;
        asn::SetBitStringLong<39>(Random::Mixed(m_base->config->getNodeName()).nextL(), m_initialId.choice.randomValue);
    }

    /* Send the message */
    m_logger->debug("Sending RRC Setup Request");

    auto *rrcSetupRequest =
        ConstructSetupRequest(m_initialId, static_cast<ASN_RRC_EstablishmentCause_t>(m_establishmentCause));
    sendRrcMessage(activeCell, rrcSetupRequest);
    asn::Free(asn_DEF_ASN_RRC_UL_CCCH_Message, rrcSetupRequest);
}

void UeRrcTask::receiveRrcSetup(int cellId, const ASN_RRC_RRCSetup &msg)
{
    if (!isActiveCell(cellId))
        return;

    if (m_lastSetupReq != ERrcLastSetupRequest::SETUP_REQUEST)
    {
        // TODO
        return;
    }

    auto *pdu = asn::New<ASN_RRC_UL_DCCH_Message>();
    pdu->message.present = ASN_RRC_UL_DCCH_MessageType_PR_c1;
    pdu->message.choice.c1 = asn::NewFor(pdu->message.choice.c1);
    pdu->message.choice.c1->present = ASN_RRC_UL_DCCH_MessageType__c1_PR_rrcSetupComplete;

    auto &setupComplete = pdu->message.choice.c1->choice.rrcSetupComplete = asn::New<ASN_RRC_RRCSetupComplete>();
    setupComplete->rrc_TransactionIdentifier = msg.rrc_TransactionIdentifier;
    setupComplete->criticalExtensions.present = ASN_RRC_RRCSetupComplete__criticalExtensions_PR_rrcSetupComplete;

    auto &ies = setupComplete->criticalExtensions.choice.rrcSetupComplete = asn::New<ASN_RRC_RRCSetupComplete_IEs>();
    ies->selectedPLMN_Identity = 1;
    asn::SetOctetString(ies->dedicatedNAS_Message, m_initialNasPdu);

    /* Send S-TMSI if available */
    std::optional<GutiMobileIdentity> gutiOrTmsi = m_base->shCtx.providedGuti.get();
    if (!gutiOrTmsi)
        gutiOrTmsi = m_base->shCtx.providedTmsi.get();
    if (gutiOrTmsi)
    {
        auto &sTmsi = setupComplete->criticalExtensions.choice.rrcSetupComplete->ng_5G_S_TMSI_Value =
            asn::New<ASN_RRC_RRCSetupComplete_IEs::ASN_RRC_RRCSetupComplete_IEs__ng_5G_S_TMSI_Value>();
        sTmsi->present = ASN_RRC_RRCSetupComplete_IEs__ng_5G_S_TMSI_Value_PR_ng_5G_S_TMSI;
        asn::SetBitStringLong<48>(gutiOrTmsi->toTmsiValue(), sTmsi->choice.ng_5G_S_TMSI);
    }

    m_initialNasPdu = {};
    sendRrcMessage(pdu);
    asn::Free(asn_DEF_ASN_RRC_UL_DCCH_Message, pdu);

    m_logger->info("RRC connection established");
    switchState(ERrcState::RRC_CONNECTED);
}

void UeRrcTask::receiveRrcReject(int cellId, const ASN_RRC_RRCReject &msg)
{
    if (!isActiveCell(cellId))
        return;

    m_logger->err("RRC Reject received");
}

void UeRrcTask::receiveRrcRelease(const ASN_RRC_RRCRelease &msg)
{
    m_logger->debug("RRC Release received");
    m_state = ERrcState::RRC_IDLE;
}

void UeRrcTask::receiveRrcUECapabilityEnquiry(const ASN_RRC_UECapabilityEnquiry &msg)
{
    m_logger->debug("UECapabilityEnquiry received");

    m_logger->info("Sending UE Capability Information");
    auto *pdu = asn::New<ASN_RRC_UL_DCCH_Message>();
    pdu->message.present = ASN_RRC_UL_DCCH_MessageType_PR_c1;
    pdu->message.choice.c1 = asn::NewFor(pdu->message.choice.c1);
    pdu->message.choice.c1->present = ASN_RRC_UL_DCCH_MessageType__c1_PR_ueCapabilityInformation;

    auto &capabilityInformation = pdu->message.choice.c1->choice.ueCapabilityInformation = asn::New<ASN_RRC_UECapabilityInformation>();
    capabilityInformation->rrc_TransactionIdentifier = msg.rrc_TransactionIdentifier;
    capabilityInformation->criticalExtensions.present = ASN_RRC_UECapabilityInformation__criticalExtensions_PR_ueCapabilityInformation;

    auto &ies = capabilityInformation->criticalExtensions.choice.ueCapabilityInformation = asn::New<ASN_RRC_UECapabilityInformation_IEs>();
    ies->ue_CapabilityRAT_ContainerList = asn::New<ASN_RRC_UE_CapabilityRAT_ContainerList>();

    OctetString octetString{};
    octetString.appendUtf8("15");

    auto *ue_CapabilityRAT_Container = asn::New<ASN_RRC_UE_CapabilityRAT_Container>();
    ue_CapabilityRAT_Container->rat_Type = ASN_RRC_RAT_Type_nr;
    asn::SetOctetString(ue_CapabilityRAT_Container->ue_CapabilityRAT_Container, octetString);

    asn::SequenceAdd(*ies->ue_CapabilityRAT_ContainerList, ue_CapabilityRAT_Container);
    //asn::SetOctetString(ies->dedicatedNAS_Message, m_initialNasPdu);

    sendRrcMessage(pdu);
    asn::Free(asn_DEF_ASN_RRC_UL_DCCH_Message, pdu);
}

} // namespace nr::ue
