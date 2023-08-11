//
// Created by Hoonyong Park on 8/9/23.
//

#pragma once

#include <set>

#include <lib/app/monitor.hpp>
#include <lib/asn/utils.hpp>
#include <utils/common_types.hpp>
#include <utils/logger.hpp>
#include <utils/network.hpp>
#include <utils/nts.hpp>
#include <utils/octet_string.hpp>

namespace nr::FBS
{

class FBSAppTask;
class FBSRrcTask;
class FUERlsTask;
class FBSRlsTask;

struct FBSConfig
{
    /* Read from config file */
    int64_t nci{};     // 36-bit
    int FBSIdLength{}; // 22..32 bit
    Plmn plmn{};
    int tac{};
    std::string linkIp{};
    std::string f1apIp{};
    std::string gtpIp{};

    bool ignoreStreamIds{};

    /* Assigned by program */
    std::string name{};
    EPagingDrx pagingDrx{};
    Vector3 phyLocation{};

    [[nodiscard]] inline uint32_t getFBSId() const
    {
        return static_cast<uint32_t>((nci & 0xFFFFFFFFFLL) >> (36LL - static_cast<int64_t>(FBSIdLength)));
    }

    [[nodiscard]] inline int getCellId() const
    {
        return static_cast<int>(nci & static_cast<uint64_t>((1 << (36 - FBSIdLength)) - 1));
    }
};

struct TaskBase
{
    FBSConfig *config{};
    LogBase *logBase{};
    app::INodeListener *nodeListener{};
    NtsTask *cliCallbackTask{};

    FBSAppTask *appTask{};
    FBSRrcTask *rrcTask{};
    FUERlsTask *rlsFUETask{};
    FBSRlsTask *rlsFBSTask{};
};

}
