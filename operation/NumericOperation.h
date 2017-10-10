#ifndef NUMERICOPERATION_H
#define NUMERICOPERATION_H

#include "../interface/AbstractOperator.h"

class NumericOperation : public AbstractOperator
{
public:
    constexpr NumericOperation() = default;
    std::shared_ptr<AbstractDataType> result(const std::list<std::shared_ptr<Expressionable>> &arg) const override;
    bool matchArguments(const std::list<std::shared_ptr<AbstractDataType>> &) const noexcept override;
    bool matchArguments(const std::list<std::shared_ptr<Expressionable>> &) const override;
    Expressionable::value_cast castValueOfResult() const noexcept override;
};

#include "../type/AbstractDataType.h"

#endif // NUMERICOPERATION_H
