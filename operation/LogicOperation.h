#ifndef LOGICOPERATION_H
#define LOGICOPERATION_H

#include "../interface/IOperation.h"

class LogicOperation : public IOperation
{
public:
    constexpr LogicOperation() noexcept = default;
    Type result(const IArguments &) override;
    bool matchArguments(const IArguments &) const noexcept override;
};

#endif // LOGICOPERATION_H
