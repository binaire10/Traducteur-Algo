#ifndef BITWISEOPERATION_H
#define BITWISEOPERATION_H

#include "../interface/AbstractOperation.h"

class BitWiseOperation : public AbstractOperation
{
public:
    constexpr BitWiseOperation(std::size_t i) noexcept;
    std::shared_ptr<AbstractDataType> result(const std::list<std::shared_ptr<Expressionable>> &) const override;
    bool matchArguments(const std::list<std::shared_ptr<AbstractDataType>> &) const noexcept override;
    bool matchArguments(const std::list<std::shared_ptr<Expressionable>> &) const noexcept override;
    Expressionable::value_cast castValueOfResult() const noexcept override;
private:
    const std::size_t m_parametersCount;
};

constexpr BitWiseOperation::BitWiseOperation(std::size_t i) noexcept : m_parametersCount(i)
{}

#endif // BITWISEOPERATION_H
