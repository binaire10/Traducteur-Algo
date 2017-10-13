#include "BreakLoop.h"
#include "../interface/IInstructionVisitor.h"

void BreakLoop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
