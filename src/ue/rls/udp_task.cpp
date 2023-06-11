//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "udp_task.hpp"

#include <set>
#include <random>
#include <chrono>

#include <iostream>
#include <iomanip>

#include <ue/nts.hpp>
#include <utils/common.hpp>
#include <utils/constants.hpp>

static constexpr const int BUFFER_SIZE = 16384;
static constexpr const int LOOP_PERIOD = 1000;
static constexpr const int RECEIVE_TIMEOUT = 200;
static constexpr const int HEARTBEAT_THRESHOLD = 2000; // (LOOP_PERIOD + RECEIVE_TIMEOUT)'dan büyük olmalı

auto nextWalkTime = std::chrono::high_resolution_clock::now();
auto currentWalkTime = std::chrono::high_resolution_clock::now();

auto nextUpdateTime = std::chrono::high_resolution_clock::now();
auto currentUpdateTime = std::chrono::high_resolution_clock::now();

void printHex(const uint8_t* data, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<int>(data[i]);
        if (i != length - 1) {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

namespace nr::ue
{

RlsUdpTask::RlsUdpTask(TaskBase *base, RlsSharedContext *shCtx, const std::vector<std::string> &searchSpace)
    : m_server{}, m_ctlTask{}, m_shCtx{shCtx}, m_searchSpace{}, m_cells{}, m_cellIdToSti{}, m_lastLoop{},
      m_cellIdCounter{}, m_speed{}, m_direction{}, bounds{Position(0, 0), Position(1500, 1500)}
{
    m_logger = base->logBase->makeUniqueLogger(base->config->getLoggerPrefix() + "rls-udp");

    m_server = new udp::UdpServer();

    for (auto &ip : searchSpace)
        m_searchSpace.emplace_back(ip, cons::RadioLinkPort);

    m_simPos = new Vector3(base->config->initPos.xpos, base->config->initPos.ypos, base->config->initPos.zpos);
}

void RlsUdpTask::onStart()
{
}



void RlsUdpTask::onLoop()
{
    auto current = utils::CurrentTimeMillis();
    if (current - m_lastLoop > LOOP_PERIOD)
    {
        m_lastLoop = current;
        heartbeatCycle(current, m_simPos);
    }

    uint8_t buffer[BUFFER_SIZE];
    InetAddress peerAddress;

    int size = m_server->Receive(buffer, BUFFER_SIZE, RECEIVE_TIMEOUT, peerAddress);
    if (size > 0)
    {
//        std::cout << "Received: ";
//        printHex(buffer, size);
        auto rlsMsg = rls::DecodeRlsMessage(OctetView{buffer, static_cast<size_t>(size)});
        if (rlsMsg == nullptr)
            m_logger->err("Unable to decode RLS message");
        else
            receiveRlsPdu(peerAddress, std::move(rlsMsg));
    }


    currentUpdateTime = std::chrono::high_resolution_clock::now();
    if (currentUpdateTime >= nextUpdateTime) {
        updateDirectionAndSpeed(5.0, 10.0, 0.0, 2 * M_PI);

        // 여기서 노드의 위치를 출력하거나, 다른 작업을 수행
//        m_logger->debug("Course Changed: m_speed = %f, m_direction = %f", m_speed, m_direction);

        // 다음 실행 시간 설정
        nextUpdateTime = currentUpdateTime + std::chrono::seconds(10);
    }

    currentWalkTime = std::chrono::high_resolution_clock::now();
    if (currentWalkTime >= nextWalkTime) {
        walk();

        // 여기서 노드의 위치를 출력하거나, 다른 작업을 수행
//        m_logger->debug("Node position: (%f, %f)", m_simPos->x, m_simPos->y);

        // 다음 실행 시간 설정
        nextWalkTime = currentWalkTime + std::chrono::milliseconds(1);
    }
}

void RlsUdpTask::walk()
{
    double proposedX = m_simPos->x + m_speed * cos(m_direction);
    double proposedY = m_simPos->y + m_speed * sin(m_direction);

    // X boundary check
    if (proposedX < bounds.topLeft.x || proposedX > bounds.bottomRight.x) {
        m_direction = M_PI - m_direction;
    } else {
        m_simPos->x = proposedX;
    }

    // Y boundary check
    if (proposedY < bounds.topLeft.y || proposedY > bounds.bottomRight.y) {
        m_direction = -m_direction;
    } else {
        m_simPos->y = proposedY;
    }
}

void RlsUdpTask::updateDirectionAndSpeed(double minSpeed, double maxSpeed, double minDirection, double maxDirection)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> speedDis(minSpeed, maxSpeed);
    std::uniform_real_distribution<> directionDis(minDirection, maxDirection);

    m_speed = speedDis(gen);
    m_direction = directionDis(gen);
}



void RlsUdpTask::onQuit()
{
    delete m_server;
}

void RlsUdpTask::sendRlsPdu(const InetAddress &addr, const rls::RlsMessage &msg)
{
    OctetString stream;
    rls::EncodeRlsMessage(msg, stream);

//    std::cout << "Send: ";
//    printHex(stream.data(), static_cast<size_t>(stream.length()));

    m_server->Send(addr, stream.data(), static_cast<size_t>(stream.length()));
}

void RlsUdpTask::send(int cellId, const rls::RlsMessage &msg)
{
    if (m_cellIdToSti.count(cellId))
    {
        auto sti = m_cellIdToSti[cellId];
        sendRlsPdu(m_cells[sti].address, msg);
    }
}

void RlsUdpTask::receiveRlsPdu(const InetAddress &addr, std::unique_ptr<rls::RlsMessage> &&msg)
{
    if (msg->msgType == rls::EMessageType::HEARTBEAT_ACK)
    {
        if (!m_cells.count(msg->sti))
        {
            m_cells[msg->sti].cellId = ++m_cellIdCounter;
            m_cellIdToSti[m_cells[msg->sti].cellId] = msg->sti;
        }

        double oldDbm = -150;
        if (m_cells.count(msg->sti))
            oldDbm = m_cells[msg->sti].dbm;

        m_cells[msg->sti].address = addr;
        m_cells[msg->sti].lastSeen = utils::CurrentTimeMillis();

        double newDbm = ((const rls::RlsHeartBeatAck &)*msg).dbm;
        m_cells[msg->sti].dbm = newDbm;

        if (oldDbm != newDbm)
            onSignalChangeOrLost(m_cells[msg->sti].cellId);
        return;
    }

    if (!m_cells.count(msg->sti))
    {
        // if no HB-ACK received yet, and the message is not HB-ACK, then ignore the message
        return;
    }

    auto w = std::make_unique<NmUeRlsToRls>(NmUeRlsToRls::RECEIVE_RLS_MESSAGE);
    w->cellId = m_cells[msg->sti].cellId;
    w->msg = std::move(msg);
    m_ctlTask->push(std::move(w));
}

void RlsUdpTask::onSignalChangeOrLost(int cellId)
{
    double dbm = -150;
    if (m_cellIdToSti.count(cellId))
    {
        auto sti = m_cellIdToSti[cellId];
        dbm = m_cells[sti].dbm;
    }

    auto w = std::make_unique<NmUeRlsToRls>(NmUeRlsToRls::SIGNAL_CHANGED);
    w->cellId = cellId;
    w->dbm = dbm;
    //m_logger->debug("Received signal dBm [%f]", dbm);
    m_ctlTask->push(std::move(w));
}

void RlsUdpTask::heartbeatCycle(uint64_t time, Vector3 *simPos)
{
    std::set<std::pair<uint64_t, int>> toRemove;

    for (auto &cell : m_cells)
    {
        auto delta = time - cell.second.lastSeen;
        if (delta > HEARTBEAT_THRESHOLD)
            toRemove.insert({cell.first, cell.second.cellId});
    }

    for (auto cell : toRemove)
    {
        m_cells.erase(cell.first);
        m_cellIdToSti.erase(cell.second);
    }

    for (auto cell : toRemove)
        onSignalChangeOrLost(cell.second);

    for (auto &addr : m_searchSpace)
    {
        rls::RlsHeartBeat msg{m_shCtx->sti};
        msg.simPos = *simPos;
        sendRlsPdu(addr, msg);
    }
}

void RlsUdpTask::initialize(NtsTask *ctlTask)
{
    m_ctlTask = ctlTask;
}

} // namespace nr::ue
