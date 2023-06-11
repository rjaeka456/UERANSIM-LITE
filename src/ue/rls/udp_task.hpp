//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#pragma once

#include <cstdint>
#include <unordered_map>
#include <vector>

#include <lib/rls/rls_pdu.hpp>
#include <lib/udp/server.hpp>
#include <ue/types.hpp>
#include <utils/nts.hpp>

namespace nr::ue
{

class RlsUdpTask : public NtsTask
{
  private:
    struct CellInfo
    {
        InetAddress address;
        int64_t lastSeen{};
        double dbm{};
        int cellId{};
    };

    class Position {
      public:
        double x;
        double y;

        Position() : x(0.0), y(0.0) {}
        Position(double x, double y) : x(x), y(y) {}
    };

    class Rectangle {
      public:
        Position topLeft;
        Position bottomRight;

        Rectangle(Position topLeft, Position bottomRight)
            : topLeft(topLeft), bottomRight(bottomRight) {}
    };


  private:
    std::unique_ptr<Logger> m_logger;
    udp::UdpServer *m_server;
    NtsTask *m_ctlTask;
    RlsSharedContext* m_shCtx;
    std::vector<InetAddress> m_searchSpace;
    std::unordered_map<uint64_t, CellInfo> m_cells;
    std::unordered_map<int, uint64_t> m_cellIdToSti;
    int64_t m_lastLoop;

    int m_cellIdCounter;

    /* Mobility Variables */
    Vector3 *m_simPos;
    double m_speed;
    double m_direction;
    Rectangle bounds;



    friend class UeCmdHandler;

  public:
    explicit RlsUdpTask(TaskBase *base, RlsSharedContext* shCtx, const std::vector<std::string> &searchSpace);
    ~RlsUdpTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;

  private:
    void sendRlsPdu(const InetAddress &addr, const rls::RlsMessage &msg);
    void receiveRlsPdu(const InetAddress &addr, std::unique_ptr<rls::RlsMessage> &&msg);
    void onSignalChangeOrLost(int cellId);
    void heartbeatCycle(uint64_t time, Vector3 *simPos);

    /* Mobility Functions */
    void walk();
    void updateDirectionAndSpeed(double minSpeed, double maxSpeed, double minDirection, double maxDirection);

  public:
    void initialize(NtsTask *ctlTask);
    void send(int cellId, const rls::RlsMessage &msg);
};

} // namespace nr::ue
