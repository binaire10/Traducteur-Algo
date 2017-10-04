#ifndef DIVISION_H
#define DIVISION_H

#include "NumericOperation.h"

class Division : public NumericOperation
{
public:
    static std::shared_ptr<Division> getInstance() noexcept;
    void visiteOperation(IOperationVisitor &) const override;

protected:
    constexpr Division() = default;
};

#endif // DIVISION_H
