#pragma once
#include "Expression.h"

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class CVariable : public Expression
        {
        public:
            CVariable(VariablePrototype * const &Value);
            CVariable(const CVariable &) = delete;
            CVariable &operator=(const CVariable &) = delete;
            void ToCppCode(std::ostream &Result) override;
            //binaire::SmartPtr<void> Execute(EnvGlobal &) override;
            bool isFinalValue() override
            {
                return false;
            }
        private:
            VariablePrototype *var;
        };
    }
}
