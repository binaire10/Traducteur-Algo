#include "Conditional.h"
#include "../interface/IInstructionVisitor.h"

void Conditional::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}
