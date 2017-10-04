#ifndef ICOMMONTYPEVISITOR_H
#define ICOMMONTYPEVISITOR_H

class Boolean;
class Character;
class Numeric;
class ICommonTypeVisitor
{
public:
    constexpr ICommonTypeVisitor() noexcept = default;
    virtual void visiteType(const Character &) = undefined;
    virtual void visiteType(const Numeric &) = undefined;
    virtual void visiteType(const Boolean &) = undefined;
};

#endif // ICOMMONTYPEVISITOR_H
