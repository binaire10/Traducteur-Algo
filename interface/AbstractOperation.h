#ifndef ABSTRACTOPERATION_H
#define ABSTRACTOPERATION_H

#include <string>
#include "IParameters.h"

class AbstractOperation
{
public:
    constexpr AbstractOperation() noexcept = default;
    virtual bool matchArguments(const IParameters &) const noexcept = undefined;
    virtual std::shared_ptr<AbstractDataType> result(const IParameters &) const = undefined;
    virtual void visiteOperation(IOperationVisitor &) const = undefined;
};

#endif // ABSTRACTOPERATION_H
