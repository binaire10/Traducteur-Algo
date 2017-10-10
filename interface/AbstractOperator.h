#ifndef ABSTRACTOPERATOR_H
#define ABSTRACTOPERATOR_H

#include "AbstractOperation.h"
#include "Expressionable.h"

class AbstractOperatorVisitor;
class AbstractOperator : public AbstractOperation
{
public:
    constexpr AbstractOperator() noexcept = default;
    virtual void visiteOperator(AbstractOperatorVisitor &) const = undefined;
};

#endif // ABSTRACTOPERATOR_H
