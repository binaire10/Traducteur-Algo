#ifndef ICOMMONABSTRACTDATAVISITOR_H
#define ICOMMONABSTRACTDATAVISITOR_H

class Boolean;
class Character;
class CommonNumeric;
class ICommonAbstractDataVisitor
{
public:
    constexpr ICommonAbstractDataVisitor() noexcept = default;
    virtual void visiteType(const Character &) = undefined;
    virtual void visiteType(const CommonNumeric &) = undefined;
    virtual void visiteType(const Boolean &) = undefined;
};

#endif // ICOMMONABSTRACTDATAVISITOR_H
