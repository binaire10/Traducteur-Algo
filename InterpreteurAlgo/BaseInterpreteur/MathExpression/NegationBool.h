#pragma once
#include "CoreExpression.h"

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class NegationBool : public Unuaire
        {
        public:
            NegationBool(const binaire::SmartPtr<Expression> &a);
            void ToCppCode(std::ostream &Result) override;
            bool isFinalValue() override;
        };
    }
}
