#ifndef LOGICOPERATION_H
#define LOGICOPERATION_H

#include "../interface/IOperation.h"

class LogicOperation : public IOperation
{
public:
    constexpr LogicOperation() noexcept = default;
    AbstractDataType result(const IParameters &) const override;
    bool matchArguments(const IParameters &) const noexcept override;
};

#endif // LOGICOPERATION_H
