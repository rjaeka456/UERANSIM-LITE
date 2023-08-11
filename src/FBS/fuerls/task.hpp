//
// Created by Hoonyong Park on 8/9/23.
//

#pragma once

#include "ctl_task.hpp"
#include "udp_task.hpp"

#include <memory>
#include <optional>
#include <thread>
#include <unordered_map>
#include <vector>

#include <lib/rls/rls_pdu.hpp>
#include <lib/rrc/rrc.hpp>
#include <lib/udp/server_task.hpp>
#include <FBS/types.hpp>
#include <utils/common_types.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::FBS
{

class FUERlsTask : public NtsTask
{
  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;

    RlsSharedContext* m_shCtx;
    RlsUdpTask *m_udpTask;
    RlsControlTask *m_ctlTask;

    friend class UeCmdHandler;

  public:
    explicit FUERlsTask(TaskBase *base);
    ~FUERlsTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;
};

}

