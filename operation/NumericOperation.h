#ifndef NUMERICOPERATION_H
#define NUMERICOPERATION_H

#include "../interface/IOperation.h"

class NumericOperation : public IOperation
{
public:
    constexpr NumericOperation() = default;
    Type result(const IArguments &arg) override;
};

#endif // NUMERICOPERATION_H
