#ifndef LOGICOPERATION_H
#define LOGICOPERATION_H

#include "../interface/AbstractOperator.h"

class LogicOperation : public AbstractOperator
{
public:
    constexpr LogicOperation(std::size_t t) noexcept : m_parametersCount(t)
    {}
    std::shared_ptr<AbstractDataType> result(const std::list<std::shared_ptr<Expressionable>> &) const override;
    bool matchArguments(const std::list<std::shared_ptr<Expressionable>> &) const override;
    bool matchArguments(const std::list<std::shared_ptr<AbstractDataType>> &) const noexcept override;
    Expressionable::value_cast castValueOfResult() const noexcept override;

private:
    const std::size_t m_parametersCount;
};

#endif // LOGICOPERATION_H
