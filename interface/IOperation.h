#ifndef IOPERATION_H
#define IOPERATION_H

#include "IOperationVisitable.h"
#include "IArguments.h"

class IOperation : IOperationVisitable
{
public:
    constexpr IOperation() noexcept = default;
    virtual Type result(const IArguments &) = undefined;
};

#endif // IOPERATION_H
