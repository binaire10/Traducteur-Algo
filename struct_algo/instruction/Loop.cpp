#include "Loop.h"
#include "../interface/IInstructionVisitor.h"

Loop::Loop(const std::shared_ptr<Instruction> &instruction) noexcept : Loopable(instruction)
{}

void Loop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
