#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include "IExpressionVisitable.h"
#include "../type/Type.h"
#include "IArguments.h"

class IExpression : public IExpressionVisitable
{
public:
    constexpr IExpression() noexcept = default;
    virtual Type result() const = undefined;
};

#endif // IEXPRESSION_H
