#ifndef IARGUMENTVISITOR_H
#define IARGUMENTVISITOR_H

class ArgumentExpression;
class ArgumentType;
class IArgumentVisitor
{
public:
    constexpr IArgumentVisitor() noexcept = default;
    virtual void visiteArgument(const ArgumentExpression &) = undefined;
    virtual void visiteArgument(const ArgumentType &) = undefined;
};

#endif // IARGUMENTVISITOR_H
