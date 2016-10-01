#pragma once
#include "BaseLoop.h"
#include "Expression.h"

namespace ElementAlgorithmique
{
    class WhileLoop : public BaseLoop
    {
    public:
        WhileLoop() = default;
        WhileLoop(const binaire::SmartPtr<Expression> &);
        void ToCppCode(std::ostream &) override;
        void setExp(const binaire::SmartPtr<Expression> &Exp);

    private:
        binaire::SmartPtr<Expression> m_Exp = {};
    };
}
