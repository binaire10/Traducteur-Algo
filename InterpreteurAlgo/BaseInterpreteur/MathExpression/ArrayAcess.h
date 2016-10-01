#pragma once
#include <MyMemory/SmartPtr.hpp>
#include "Expression.h"
#include "VariablePrototype.h"

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class ArrayAccess : public Expression
        {
        public:
            ArrayAccess(VariablePrototype * const &Value, const binaire::SmartPtr<Expression> &i);
            ArrayAccess(const ArrayAccess &) = delete;
            ArrayAccess &operator=(const ArrayAccess &) = delete;

            void ToCppCode(std::ostream &Result) override;
            bool isFinalValue() override;
            //binaire::SmartPtr<void> Execute(EnvGlobal &) override;
        private:
            VariablePrototype *m_var;
            binaire::SmartPtr<Expression> i;
        };
    }
}
