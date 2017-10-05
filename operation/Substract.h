#ifndef SUBSTRACT_H
#define SUBSTRACT_H

#include "NumericOperation.h"

class Substract : public NumericOperation
{
public:
    static std::shared_ptr<Substract> getInstance() noexcept;
    void visiteOperation(IOperationVisitor &) const override;
    void visiteOperator(IOperatorVisitor &) const override;

protected:
    constexpr Substract() noexcept = default;
};

#endif // SUBSTRACT_H
