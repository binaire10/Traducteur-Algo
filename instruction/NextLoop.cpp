#include "NextLoop.h"
#include "../interface/IInstructionVisitor.h"

void NextLoop::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
