#ifndef IARGUMENTVISITOR_H
#define IARGUMENTVISITOR_H

class ArgumentExpression;
class TypeParameters;
class IParametersVisitor
{
public:
    constexpr IParametersVisitor() noexcept = default;
    virtual void visiteArgument(const ArgumentExpression &) = undefined;
    virtual void visiteArgument(const TypeParameters &) = undefined;
};

#endif // IARGUMENTVISITOR_H
