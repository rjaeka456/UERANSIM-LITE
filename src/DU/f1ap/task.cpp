//
// Created by Hoonyong Park on 5/25/23.
//

#include "task.hpp"

#include <DU/sctp/task.hpp>

namespace nr::DU
{

F1apTask::F1apTask(TaskBase *base) : m_base{base}, m_logger{}, m_cuCtx{}
{
    m_logger = m_base->logBase->makeUniqueLogger("f1ap");
}

void F1apTask::onStart()
{
    for (auto &cuConfig : m_base->config->cuConfigs)
        createCUContext(cuConfig);
    if (m_cuCtx == nullptr)
        m_logger->warn("No CU configuration is provided");

    auto msg = std::make_unique<NmDUSctp>(NmDUSctp::CONNECTION_REQUEST);
    msg->clientId = m_cuCtx->ctxId;
    msg->localAddress = m_base->config->f1apIp;
    msg->localPort = 0;
    msg->remoteAddress = m_cuCtx->address;
    msg->remotePort = m_cuCtx->port;
    msg->ppid = sctp::PayloadProtocolId::F1AP;
    msg->associatedTask = this;
    m_base->sctpTask->push(std::move(msg));
}

void F1apTask::onLoop()
{
}

void F1apTask::onQuit()
{
    delete m_cuCtx;
}

void F1apTask::createCUContext(const DUCUConfig &conf)
{
    auto *ctx = new F1apCUContext();
    ctx->ctxId = 0;
    //ctx->state = EAmfState::NOT_CONNECTED;
    ctx->address = conf.address;
    ctx->port = conf.port;
    m_cuCtx = ctx;
}

}