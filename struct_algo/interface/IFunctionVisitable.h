#ifndef IFUNCTIONVISITABLE_H
#define IFUNCTIONVISITABLE_H

class IFunctionVisitor;
class IFunctionVisitable
{
public:
    constexpr IFunctionVisitable() noexcept = default;
    virtual void visiteFunction(IFunctionVisitor &) const = undefined;
};

#endif // IFUNCTIONVISITABLE_H
