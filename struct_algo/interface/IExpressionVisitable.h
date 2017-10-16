#ifndef IEXPRESSIONVISITABLE_H
#define IEXPRESSIONVISITABLE_H

class IExpressionVisitor;
class IExpressionVisitable
{
public:
    constexpr IExpressionVisitable() noexcept = default;
    virtual void visiteExpression(IExpressionVisitor &) const = undefined;
};

#endif // IEXPRESSIONVISITABLE_H
