//
// Created by Hoonyong Park on 8/10/23.
//

#pragma once

#pragma once

#include <memory>
#include <thread>
#include <unordered_map>
#include <vector>

#include <FBS/types.hpp>
#include <utils/logger.hpp>
#include <utils/nts.hpp>

namespace nr::FBS
{

class FBSAppTask : public NtsTask
{
  private:
    TaskBase *m_base;
    std::unique_ptr<Logger> m_logger;

    DUStatusInfo m_statusInfo;

    friend class FBSCmdHandler;

  public:
    explicit FBSAppTask(TaskBase *base);
    ~FBSAppTask() override = default;

  protected:
    void onStart() override;
    void onLoop() override;
    void onQuit() override;
};

}
