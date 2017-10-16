#ifndef INSTRUCTABLE_H
#define INSTRUCTABLE_H

#include "IInstructionVisitable.h"

class Instructable : public IInstructionVisitable
{
public:
    constexpr Instructable() noexcept = default;
};

#endif // INSTRUCTABLE_H
