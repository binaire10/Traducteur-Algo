#ifndef IARGUMENTVISITABLE_H
#define IARGUMENTVISITABLE_H

class IArgumentVisitor;
class IArgumentVisitable
{
public:
    constexpr IArgumentVisitable() noexcept = default;
    virtual void visiteArgument(IArgumentVisitor &) const = undefined;
};

#endif // IARGUMENTVISITABLE_H
