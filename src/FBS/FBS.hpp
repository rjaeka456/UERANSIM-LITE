//
// Created by Hoonyong Park on 8/9/23.
//

#pragma once

#include "types.hpp"

#include <lib/app/cli_cmd.hpp>
#include <lib/app/monitor.hpp>
#include <utils/logger.hpp>
#include <utils/network.hpp>
#include <utils/nts.hpp>

namespace nr::FBS
{

class FalseBaseStation
{
  private:
    TaskBase *taskBase;

  public:
    FalseBaseStation(FBSConfig *config, app::INodeListener *nodeListener, NtsTask *cliCallbackTask);
    virtual ~FalseBaseStation();

  public:
    void start();

};

}


