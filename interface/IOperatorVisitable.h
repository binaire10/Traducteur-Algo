#ifndef IOPERATORVISITABLE_H
#define IOPERATORVISITABLE_H

class IOperatorVisitor;
class IOperatorVisitable
{
public:
    constexpr IOperatorVisitable() noexcept = default;
    virtual void visiteOperator(IOperatorVisitor &) const = undefined;
};

#endif // IOPERATORVISITABLE_H
