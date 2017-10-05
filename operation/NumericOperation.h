#ifndef NUMERICOPERATION_H
#define NUMERICOPERATION_H

#include "../interface/IOperation.h"

class NumericOperation : public IOperation
{
public:
    constexpr NumericOperation() = default;
    AbstractDataType result(const IParameters &arg) const override;
    bool matchArguments(const IParameters &) const noexcept override;
};

#endif // NUMERICOPERATION_H
