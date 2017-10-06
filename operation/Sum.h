#ifndef SUM_H
#define SUM_H

#include "NumericOperation.h"

class Sum : public NumericOperation
{
public:
    static std::shared_ptr<Sum> getInstance() noexcept;
    void visiteOperation(AbstractOperationVisitor &) const override;
    void visiteOperator(AbstractOperatorVisitor &) const override;

protected:
    constexpr Sum() noexcept = default;
};

#endif // SUM_H
