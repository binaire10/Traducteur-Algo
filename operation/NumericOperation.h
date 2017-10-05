#ifndef NUMERICOPERATION_H
#define NUMERICOPERATION_H

#include "../interface/IOperator.h"

class NumericOperation : public IOperator
{
public:
    constexpr NumericOperation() = default;
    AbstractDataType result(const IParameters &arg) const override;
    bool matchArguments(const IParameters &) const noexcept override;
};

#endif // NUMERICOPERATION_H
