#include "NextLoop.h"
#include "../interface/IInstructionVisitor.h"

NextLoop::NextLoop(const std::shared_ptr<Loopable> &loop) noexcept : LoopInstruction(loop)
{}

void NextLoop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
