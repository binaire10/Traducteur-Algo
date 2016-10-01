#pragma once
#include "CoreExpression.h"

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class OuLogique : public Binaire
        {
        public:
            OuLogique(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b);
            void ToCppCode(std::ostream &Result) override;
            bool isFinalValue() override;
        };
    }
}
