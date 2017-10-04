#ifndef BITWISEOPERATION_H
#define BITWISEOPERATION_H

#include "../interface/IOperation.h"

class BitWiseOperation : public IOperation
{
public:
    constexpr BitWiseOperation() noexcept = default;
    Type result(const IArguments &) override;
};

#endif // BITWISEOPERATION_H
