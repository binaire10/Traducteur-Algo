#pragma once
#include "CoreExpression.h"


namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class ForceExpression : public Unuaire
        {
        public:
            ForceExpression(const binaire::SmartPtr<Expression> &x);

            // ExpressionInfo interface
        public:
            void ToCppCode(std::ostream &) override;
            bool isFinalValue() override;
        };
    }
}
