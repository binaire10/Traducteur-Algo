#pragma once
#include "CoreExpression.h"


namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class LessOrEqualThan : public Binaire
        {
        public:
            LessOrEqualThan(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b);
            void ToCppCode(std::ostream &os) override;
            bool isFinalValue() override;
        };
    }
}
