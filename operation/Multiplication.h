#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "NumericOperation.h"

class Multiplication : public NumericOperation
{
public:
    static std::shared_ptr<Multiplication> getInstance() noexcept;
    void visiteOperation(IOperationVisitor &) const override;

protected:
    constexpr Multiplication() = default;
};

#endif // MULTIPLICATION_H
