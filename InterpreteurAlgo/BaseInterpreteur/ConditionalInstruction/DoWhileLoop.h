#pragma once
#include "BaseLoop.h"
#include "Expression.h"

namespace ElementAlgorithmique
{
    class DoWhileLoop : public BaseLoop
    {
    public:
        DoWhileLoop() = default;
        DoWhileLoop(const binaire::SmartPtr<Expression> &exp) noexcept;
        DoWhileLoop(const binaire::SmartPtr<Expression> &exp, const std::list<binaire::SmartPtr<Instruction> > &inst) noexcept;
        void ToCppCode(std::ostream &) override;
        const binaire::SmartPtr<Expression> &Exp() const;
        void setExp(const binaire::SmartPtr<Expression> &Exp);

    private:
        binaire::SmartPtr<Expression> m_Exp = binaire::SmartPtr<Expression>();
    };
}
