#ifndef ITYPEVISITABLE_H
#define ITYPEVISITABLE_H

class ITypeVisitor;
class ITypeVisitable
{
public:
    ITypeVisitable() noexcept = default;
    virtual void visiteType(ITypeVisitor &) const = undefined;
};

#endif // ITYPEVISITABLE_H
