#include "ForLoop.h"
#include "../interface/IInstructionVisitor.h"

void ForLoop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
