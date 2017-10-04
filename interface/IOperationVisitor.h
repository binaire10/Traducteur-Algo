#ifndef IOPERATIONVISITOR_H
#define IOPERATIONVISITOR_H

namespace BitWise
{
    class Or;
    class And;
    class Not;
}
namespace Logic
{
    class Or;
    class And;
    class Not;
}
class Sum;
class Substract;
class Division;
class Multiplication;
class IOperationVisitor
{
public:
    constexpr IOperationVisitor() noexcept = default;
    virtual void visiteOperation(const BitWise::Or &) = undefined;
    virtual void visiteOperation(const Logic::Or &) = undefined;
    virtual void visiteOperation(const BitWise::And &) = undefined;
    virtual void visiteOperation(const Logic::And &) = undefined;
    virtual void visiteOperation(const BitWise::Not &) = undefined;
    virtual void visiteOperation(const Logic::Not &) = undefined;
    virtual void visiteOperation(const Sum &) = undefined;
    virtual void visiteOperation(const Substract &) = undefined;
    virtual void visiteOperation(const Multiplication &) = undefined;
    virtual void visiteOperation(const Division &) = undefined;
};

#endif // IOPERATIONVISITOR_H