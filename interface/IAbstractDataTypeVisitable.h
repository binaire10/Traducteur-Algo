#ifndef ITYPEVISITABLE_H
#define ITYPEVISITABLE_H

class IAbstractDataTypeVisitor;
class IAbstractDataTypeVisitable
{
public:
    IAbstractDataTypeVisitable() noexcept = default;
    virtual void visiteType(IAbstractDataTypeVisitor &) const = undefined;
};

#endif // ITYPEVISITABLE_H
