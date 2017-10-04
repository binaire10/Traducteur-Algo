#ifndef NUMERICOPERATION_H
#define NUMERICOPERATION_H

#include "../interface/IOperation.h"

class NumericOperation : public IOperation
{
public:
    constexpr NumericOperation() = default;
    AbstractDataType result(const IArguments &arg) const override;
    bool matchArguments(const IArguments &) const noexcept override;
};

#endif // NUMERICOPERATION_H
