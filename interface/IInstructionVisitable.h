#ifndef INSTRUCTIONVISITABLE_H
#define INSTRUCTIONVISITABLE_H

#include "IInstructionVisitor.h"

class IInstructionVisitable
{
public:
    constexpr IInstructionVisitable() noexcept = default;
    virtual void visiteInstruction(IInstructionVisitor &) const = undefined;
};

#endif // INSTRUCTIONVISITABLE_H
