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

#define hysteresis_parameter 3
#define A2_Threshold -70
#define A4_Threshold -80
#define NeighCellOffset 1

namespace nr::ue
{

void UeRrcTask::checkMeasurementreportTriggered()
{
    if ( m_state != ERrcState::RRC_CONNECTED)
    {
        return;
    }

    int servingCellId = m_base->shCtx.currentCell.get<int>([](auto &value) { return value.cellId; });
    auto servingCell = m_cellDesc[servingCellId];

    auto *neighCell = new UeCellDesc[m_cellDesc.size() - 1];

    int i = 0;
    for (auto &a : m_cellDesc)
    {
        if (a.first != servingCellId)
            neighCell[i++] = a.second;
    }

    if (servingCell.dbm + hysteresis_parameter < A2_Threshold) // Event A2 Triggering
    {
        eventA2Trigger = true;
    }

    for (int j = 0; j < i; j++)
    {
        if (neighCell[j].dbm + NeighCellOffset - hysteresis_parameter > A4_Threshold) // Event A4 Triggering
        {
            eventA4Trigger = true;
            break;
        }
    }

    if (servingCell.dbm - hysteresis_parameter > A2_Threshold) // Event A2 Cancellation
    {
        eventA2Trigger = false;
    }

    for (int j = 0; j < i; j++)
    {
        if (neighCell[j].dbm + NeighCellOffset + hysteresis_parameter < A4_Threshold) // Event A4 Cancellation
        {
            eventA4Trigger = false;
            break;
        }
    }
}

void UeRrcTask::handleCellSignalChange(int cellId, double dbm)
{
    bool considerLost = dbm < -120;

    if (!m_cellDesc.count(cellId))
    {
        if (!considerLost)
            notifyCellDetected(cellId, dbm);
    }
    else
    {
        if (considerLost)
            notifyCellLost(cellId);
        else
        {
            m_cellDesc[cellId].dbm = dbm;
            checkMeasurementreportTriggered();
        }
    }
}

void UeRrcTask::notifyCellDetected(int cellId, double dbm)
{
    m_cellDesc[cellId] = {};
    m_cellDesc[cellId].dbm = dbm;

    m_logger->debug("New signal detected for cell[%d], total [%d] cells in coverage", cellId,
                    static_cast<int>(m_cellDesc.size()));
}

void UeRrcTask::notifyCellLost(int cellId)
{
    if (!m_cellDesc.count(cellId))
        return;

    bool isActiveCell = false;
    ActiveCellInfo lastActiveCell;
    m_base->shCtx.currentCell.mutate([&isActiveCell, &lastActiveCell, cellId](auto &value) {
        if (value.cellId == cellId)
        {
            lastActiveCell = value;
            value = {};
            isActiveCell = true;
        }
    });

    m_cellDesc.erase(cellId);

    m_logger->debug("Signal lost for cell[%d], total [%d] cells in coverage", cellId,
                    static_cast<int>(m_cellDesc.size()));

}

bool UeRrcTask::hasSignalToCell(int cellId)
{
    return m_cellDesc.count(cellId);
}

bool UeRrcTask::isActiveCell(int cellId)
{
    return m_base->shCtx.currentCell.get<int>([](auto &value) { return value.cellId; }) == cellId;
}

} // namespace nr::ue
