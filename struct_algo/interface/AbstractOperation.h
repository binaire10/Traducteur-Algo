#ifndef ABSTRACTOPERATION_H
#define ABSTRACTOPERATION_H

#include <list>
#include <string>
#include <memory>
#include "../interface/Expressionable.h"

class AbstractDataType;
class AbstractOperationVisitor;
class AbstractOperation
{
public:
    constexpr AbstractOperation() noexcept = default;
    virtual bool matchArguments(const std::list<std::shared_ptr<AbstractDataType>> &) const noexcept = undefined;
    virtual bool matchArguments(const std::list<std::shared_ptr<Expressionable>> &) const noexcept = undefined;
    virtual std::shared_ptr<AbstractDataType> result(const std::list<std::shared_ptr<Expressionable>> &) const = undefined;
    virtual void visiteOperation(AbstractOperationVisitor &) const = undefined;
    virtual Expressionable::value_cast castValueOfResult() const noexcept = undefined;
};

#endif // ABSTRACTOPERATION_H
