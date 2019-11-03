// word-grid
// Copyright (c) 2019 Borislav Stanimirov
//
// Distributed under the MIT Software License
// See accompanying file LICENSE.txt or copy at
// https://opensource.org/licenses/MIT
//
#include "ExecutorBase.hpp"
#include "ExecutionContext.hpp"

namespace server
{

namespace
{

class NoopExecutionContext final : public ExecutionContext
{
    virtual void wakeUp(ExecutorBase&) override {}
    virtual void stop(ExecutorBase&) override {}
}
TheNoopExecution;

}

ExecutorBase::ExecutorBase() : m_executionContext(&TheNoopExecution) {}
ExecutorBase::~ExecutorBase() = default;

ExecutionContext* ExecutorBase::setExecutionContext(ExecutionContext* context)
{
    auto old = m_executionContext;
    m_executionContext = context;
    return old;
}

void ExecutorBase::wakeUp()
{
    m_executionContext->wakeUp(*this);
}

void ExecutorBase::stop()
{
    m_executionContext->stop(*this);
}

}
