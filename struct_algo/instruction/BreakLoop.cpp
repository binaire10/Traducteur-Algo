#include "BreakLoop.h"
#include "../interface/IInstructionVisitor.h"

BreakLoop::BreakLoop(const std::shared_ptr<Loopable> &loop) noexcept : LoopInstruction(loop)
{}

void BreakLoop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
