#ifndef IINSTRUCTION_H
#define IINSTRUCTION_H

#include "IInstructionVisitable.h"

class IInstruction : public IInstructionVisitable
{
public:
    constexpr IInstruction() noexcept = default;
};

#endif // IINSTRUCTION_H
