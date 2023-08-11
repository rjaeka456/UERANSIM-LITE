//
// Created by Hoonyong Park on 8/9/23.
//

#pragma once

#include "ctl_task.hpp"
#include "udp_task.hpp"

#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>

#include <FBS/nts.hpp>
#include <FBS/types.hpp>
#include <lib/rls/rls_pdu.hpp>
#include <lib/udp/server_task.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::FBS
{

class FBSRlsTask : public NtsTask
{
  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;

    FBSRlsUdpTask *m_udpTask;
    FBSRlsControlTask *m_ctlTask;

    uint64_t m_sti;

    friend class GnbCmdHandler;

  public:
    explicit FBSRlsTask(TaskBase *base);
    ~FBSRlsTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;
};

}