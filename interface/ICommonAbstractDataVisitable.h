#ifndef ICOMMONABSTRACTDATAVISITABLE_H
#define ICOMMONABSTRACTDATAVISITABLE_H

class ICommonAbstractDataVisitor;
class ICommonAbstractDataVisitable
{
public:
    constexpr ICommonAbstractDataVisitable() noexcept = default;
    virtual void visiteCommonType(ICommonAbstractDataVisitor &) const = undefined;
};

#endif // ICOMMONABSTRACTDATAVISITABLE_H
