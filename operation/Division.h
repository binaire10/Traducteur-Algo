#ifndef DIVISION_H
#define DIVISION_H

#include "NumericOperation.h"

class Division : public NumericOperation
{
public:
    static std::shared_ptr<Division> getInstance() noexcept;
    void visiteOperation(AbstractOperationVisitor &) const override;

protected:
    constexpr Division() noexcept = default;
};

#endif // DIVISION_H
