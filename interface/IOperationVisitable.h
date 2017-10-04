#ifndef IOPERATIONVISITABLE_H
#define IOPERATIONVISITABLE_H

class IOperationVisitor;
class IOperationVisitable
{
public:
    constexpr IOperationVisitable() noexcept = default;
    virtual void visiteOperation(IOperationVisitor &) const = undefined;
};

#endif // IOPERATIONVISITABLE_H
