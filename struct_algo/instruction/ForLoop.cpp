#include "ForLoop.h"
#include "../interface/IInstructionVisitor.h"

ForLoop::ForLoop(const std::shared_ptr<Expressionable> &whileCondition, const std::shared_ptr<Instructable> &instruction, const std::shared_ptr<Instructable> &afterEachLoop) noexcept : Loopable(instruction), m_whileCondition(whileCondition), m_afterEachLoop(afterEachLoop)
{}

void ForLoop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}

std::shared_ptr<Expressionable> ForLoop::whileCondition() const
{
    return m_whileCondition;
}

std::shared_ptr<Instructable> ForLoop::afterEachLoop() const
{
    return m_afterEachLoop;
}
