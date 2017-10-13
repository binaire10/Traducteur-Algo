#include "Loop.h"
#include "../interface/IInstructionVisitor.h"

void Loop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
