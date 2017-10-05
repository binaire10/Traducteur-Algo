#ifndef IPARAMETERSVISITABLE_H
#define IPARAMETERSVISITABLE_H

class IParametersVisitor;
class IParametersVisitable
{
public:
    constexpr IParametersVisitable() noexcept = default;
    virtual void visiteArgument(IParametersVisitor &) const = undefined;
};

#endif // IPARAMETERSVISITABLE_H
