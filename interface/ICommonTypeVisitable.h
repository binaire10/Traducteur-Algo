#ifndef ICOMMONTYPEVISITABLE_H
#define ICOMMONTYPEVISITABLE_H

class ICommonTypeVisitor;
class ICommonTypeVisitable
{
public:
    constexpr ICommonTypeVisitable() noexcept = default;
    virtual void visiteCommonType(ICommonTypeVisitor &) const = undefined;
};

#endif // ICOMMONTYPEVISITABLE_H
