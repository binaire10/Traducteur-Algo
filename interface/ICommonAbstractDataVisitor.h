#ifndef ICOMMONABSTRACTDATAVISITOR_H
#define ICOMMONABSTRACTDATAVISITOR_H

class Boolean;
class Character;
class Numeric;
class ICommonAbstractDataVisitor
{
public:
    constexpr ICommonAbstractDataVisitor() noexcept = default;
    virtual void visiteType(const Character &) = undefined;
    virtual void visiteType(const Numeric &) = undefined;
    virtual void visiteType(const Boolean &) = undefined;
};

#endif // ICOMMONABSTRACTDATAVISITOR_H
