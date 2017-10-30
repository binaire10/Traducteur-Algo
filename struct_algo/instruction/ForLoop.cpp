#include "ForLoop.h"
#include "../interface/IInstructionVisitor.h"

ForLoop::ForLoop(const std::shared_ptr<Expression> &whileCondition, const std::shared_ptr<Instruction> &instruction, const std::shared_ptr<Instruction> &afterEachLoop) noexcept : Loopable(instruction), m_whileCondition(whileCondition), m_afterEachLoop(afterEachLoop)
{}

void ForLoop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}

std::shared_ptr<Expression> ForLoop::whileCondition() const
{
    return m_whileCondition;
}

std::shared_ptr<Instruction> ForLoop::afterEachLoop() const
{
    return m_afterEachLoop;
}
