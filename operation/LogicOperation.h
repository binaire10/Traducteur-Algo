#ifndef LOGICOPERATION_H
#define LOGICOPERATION_H

#include "../interface/IOperator.h"

class LogicOperation : public IOperator
{
public:
    constexpr LogicOperation(std::size_t t) noexcept : m_parametersCount(t)
    {}
    AbstractDataType result(const IParameters &) const override;
    bool matchArguments(const IParameters &) const noexcept override;

private:
    const std::size_t m_parametersCount;
};

#endif // LOGICOPERATION_H
