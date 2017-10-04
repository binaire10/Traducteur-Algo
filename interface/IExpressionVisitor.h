#ifndef IEXPRESSIONVISITOR_H
#define IEXPRESSIONVISITOR_H

#include <string>

template<typename>
class ValueExpression;
class Expression;
class IExpressionVisitor
{
public:
    constexpr IExpressionVisitor() noexcept = default;
    virtual void visiteExpression(const Expression &) = undefined;
    virtual void visiteExpression(const ValueExpression<std::string> &) = undefined;
    virtual void visiteExpression(const ValueExpression<char> &) = undefined;
    virtual void visiteExpression(const ValueExpression<short> &) = undefined;
    virtual void visiteExpression(const ValueExpression<unsigned short> &) = undefined;
    virtual void visiteExpression(const ValueExpression<int> &) = undefined;
    virtual void visiteExpression(const ValueExpression<unsigned> &) = undefined;
    virtual void visiteExpression(const ValueExpression<long long> &) = undefined;
    virtual void visiteExpression(const ValueExpression<unsigned long long> &) = undefined;
};

#endif // IEXPRESSIONVISITOR_H
