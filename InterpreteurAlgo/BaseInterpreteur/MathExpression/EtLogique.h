#pragma once
#include "CoreExpression.h"

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class EtLogique : public Binaire
        {
        public:
            EtLogique(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b);
            void ToCppCode(std::ostream &Result) override;
            bool isFinalValue() override;
        };
    }
}
