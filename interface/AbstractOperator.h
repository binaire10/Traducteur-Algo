#ifndef ABSTRACTOPERATOR_H
#define ABSTRACTOPERATOR_H

#include "AbstractOperation.h"

class AbstractOperatorVisitor;
class AbstractOperator : public AbstractOperation
{
public:
    constexpr AbstractOperator() noexcept = default;
    virtual std::shared_ptr<AbstractDataType> result(const IParameters &arg) const = undefined;
    virtual void visiteOperator(AbstractOperatorVisitor &) const = undefined;
};

#endif // ABSTRACTOPERATOR_H
