#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "IInstructionVisitable.h"

class Instruction : public IInstructionVisitable
{
public:
    constexpr Instruction() noexcept = default;
};

#endif // INSTRUCTION_H
