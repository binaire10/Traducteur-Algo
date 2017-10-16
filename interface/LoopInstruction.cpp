#include "LoopInstruction.h"

std::shared_ptr<Loopable> LoopInstruction::loop() const noexcept
{
    return m_loop;
}

LoopInstruction::LoopInstruction(const std::shared_ptr<Loopable> &loop) noexcept : m_loop(loop)
{}
