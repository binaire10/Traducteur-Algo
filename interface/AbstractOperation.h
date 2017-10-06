#ifndef ABSTRACTOPERATION_H
#define ABSTRACTOPERATION_H

#include <string>
#include "IParameters.h"

class AbstractOperationVisitor;
class AbstractOperation
{
public:
    constexpr AbstractOperation() noexcept = default;
    virtual bool matchArguments(const IParameters &) const noexcept = undefined;
    virtual std::shared_ptr<AbstractDataType> result(const IParameters &) const = undefined;
    virtual void visiteOperation(AbstractOperationVisitor &) const = undefined;
};

#endif // ABSTRACTOPERATION_H
