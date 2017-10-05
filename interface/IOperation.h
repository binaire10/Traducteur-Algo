#ifndef IOPERATION_H
#define IOPERATION_H

#include "IOperationVisitable.h"
#include "IParameters.h"

class IOperation : IOperationVisitable
{
public:
    constexpr IOperation() noexcept = default;
    virtual bool matchArguments(const IParameters &) const noexcept = undefined;
    virtual AbstractDataType result(const IParameters &) const = undefined;
};

#endif // IOPERATION_H
