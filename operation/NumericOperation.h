#ifndef NUMERICOPERATION_H
#define NUMERICOPERATION_H

#include "../interface/AbstractOperator.h"

class NumericOperation : public AbstractOperator
{
public:
    constexpr NumericOperation() = default;
    std::shared_ptr<AbstractDataType> result(const IParameters &arg) const override;
    bool matchArguments(const IParameters &) const noexcept override;
};

#include "../type/AbstractDataType.h"

#endif // NUMERICOPERATION_H
