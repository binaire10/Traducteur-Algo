#include "Loop.h"
#include "../interface/IInstructionVisitor.h"

Loop::Loop(const std::shared_ptr<Instructable> &instruction) noexcept : Loopable(instruction)
{}

void Loop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
