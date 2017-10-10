#ifndef ABSTRACTOPERATORVISITOR_H
#define ABSTRACTOPERATORVISITOR_H

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
class SizeOfArray;
class AbstractOperatorVisitor
{
public:
    constexpr AbstractOperatorVisitor() noexcept = default;
    virtual void visiteOperator(const BitWise::Or &) = undefined;
    virtual void visiteOperator(const Logic::Or &) = undefined;
    virtual void visiteOperator(const BitWise::And &) = undefined;
    virtual void visiteOperator(const Logic::And &) = undefined;
    virtual void visiteOperator(const BitWise::Not &) = undefined;
    virtual void visiteOperator(const Logic::Not &) = undefined;
    virtual void visiteOperator(const Sum &) = undefined;
    virtual void visiteOperator(const Substract &) = undefined;
    virtual void visiteOperator(const Multiplication &) = undefined;
    virtual void visiteOperator(const Division &) = undefined;
    virtual void visiteOperator(const SizeOfArray &) = undefined;
};

#endif // ABSTRACTOPERATORVISITOR_H
