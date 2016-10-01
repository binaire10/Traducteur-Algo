#pragma once
#include <MyMemory/SmartPtr.hpp>
#include <ostream>
#include "Expression.h"
#include "CoreExpression.h"

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class Affectation : public Binaire
        {
        public:
            Affectation(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b);
            void ToCppCode(std::ostream &Result) override;
            bool isFinalValue() override;
            //binaire::SmartPtr<void> Execute(EnvGlobal &) override;
        };
    }
}
