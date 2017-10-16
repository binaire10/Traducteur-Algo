#ifndef NUMERICOPERATION_H
#define NUMERICOPERATION_H

#include "../interface/AbstractOperation.h"

class NumericOperation : public AbstractOperation
{
public:
    constexpr NumericOperation() = default;
    std::shared_ptr<AbstractDataType> result(const std::list<std::shared_ptr<Expressionable>> &arg) const override;
    bool matchArguments(const std::list<std::shared_ptr<AbstractDataType>> &) const noexcept override;
    bool matchArguments(const std::list<std::shared_ptr<Expressionable>> &) const noexcept override;
    Expressionable::value_cast castValueOfResult() const noexcept override;
};

#include "../type/AbstractDataType.h"

#endif // NUMERICOPERATION_H
