#ifndef IEXPRESSION_H
#define IEXPRESSION_H

#include "IExpressionVisitable.h"
#include "../type/AbstractDataType.h"
#include "IParameters.h"

class IExpression : public IExpressionVisitable
{
public:
    constexpr IExpression() noexcept = default;
    virtual AbstractDataType result() const = undefined;
};

#endif // IEXPRESSION_H
