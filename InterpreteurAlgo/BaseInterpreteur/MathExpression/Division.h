#pragma once
#include "CoreExpression.h"

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class Division : public Binaire
        {
        public:
            Division(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b);
            void ToCppCode(std::ostream &Result) override;
            bool isFinalValue() override;
            //binaire::SmartPtr<void> Execute(EnvGlobal &) override;
        };
    }
}
