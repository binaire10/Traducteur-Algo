#ifndef BITWISEOPERATION_H
#define BITWISEOPERATION_H

#include "../interface/IOperation.h"

class BitWiseOperation : public IOperation
{
public:
    constexpr BitWiseOperation() noexcept = default;
    AbstractDataType result(const IParameters &) const override;
    bool matchArguments(const IParameters &) const noexcept override;
};

#endif // BITWISEOPERATION_H
