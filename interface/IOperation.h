#ifndef IOPERATION_H
#define IOPERATION_H

#include "IOperationVisitable.h"
#include "IParameters.h"

class AbstractDataType;
class IOperation : IOperationVisitable
{
public:
    constexpr IOperation() noexcept = default;
    virtual bool matchArguments(const IParameters &) const noexcept = undefined;
    virtual std::shared_ptr<AbstractDataType> result(const IParameters &) const = undefined;
};

#include "../type/AbstractDataType.h"

#endif // IOPERATION_H
