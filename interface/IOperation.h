#ifndef IOPERATION_H
#define IOPERATION_H

#include "IOperationVisitable.h"
#include "IArguments.h"

class IOperation : IOperationVisitable
{
public:
    constexpr IOperation() noexcept = default;
    virtual bool matchArguments(const IArguments &) const noexcept = undefined;
    virtual Type result(const IArguments &) const = undefined;
};

#endif // IOPERATION_H
