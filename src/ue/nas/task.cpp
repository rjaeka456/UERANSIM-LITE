//
// This file is a part of UERANSIM open source project.
// Copyright (c) 2021 ALİ GÜNGÖR.
//
// The software and all associated files are licensed under GPL-3.0
// and subject to the terms and conditions defined in LICENSE file.
//

#include "task.hpp"
#include <ue/nts.hpp>

static const int NTS_TIMER_ID_NAS_TIMER_CYCLE = 1;
static const int NTS_TIMER_ID_MM_CYCLE = 2;
static const int NTS_TIMER_INTERVAL_NAS_TIMER_CYCLE = 1000;
static const int NTS_TIMER_INTERVAL_MM_CYCLE = 1100;

namespace nr::ue
{

NasTask::NasTask(TaskBase *base) : base{base}, timers{}
{
    logger = base->logBase->makeUniqueLogger(base->config->getLoggerPrefix() + "nas");

    usim = new Usim();
}

void NasTask::onStart()
{
    usim->initialize(base->config->supi.has_value());

    setTimer(NTS_TIMER_ID_NAS_TIMER_CYCLE, NTS_TIMER_INTERVAL_NAS_TIMER_CYCLE);
    setTimer(NTS_TIMER_ID_MM_CYCLE, NTS_TIMER_INTERVAL_MM_CYCLE);
}

void NasTask::onQuit()
{
    delete usim;
}

void NasTask::onLoop()
{
    auto msg = take();
    if (!msg)
        return;

    switch (msg->msgType)
    {
    default:
        logger->unhandledNts(*msg);
        break;
    }
}

} // namespace nr::ue