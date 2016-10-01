#pragma once
#include "CoreExpression.h"


namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class LessThan : public Binaire
        {
        public:
            LessThan(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b);
            void ToCppCode(std::ostream &os) override;
            bool isFinalValue() override;
        };
    }
}
