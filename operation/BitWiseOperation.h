#ifndef BITWISEOPERATION_H
#define BITWISEOPERATION_H

#include "../interface/IOperator.h"

class BitWiseOperation : public IOperator
{
public:
    constexpr BitWiseOperation(std::size_t i) noexcept;
    AbstractDataType result(const IParameters &) const override;
    bool matchArguments(const IParameters &) const noexcept override;
private:
    const std::size_t m_parametersCount;
};

constexpr BitWiseOperation::BitWiseOperation(std::size_t i) noexcept : m_parametersCount(i)
{}

#endif // BITWISEOPERATION_H
