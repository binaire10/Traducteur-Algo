#pragma once
#include <MyMemory/SmartPtr.hpp>
#include "Expression.h"
#include "VariablePrototype.h"

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class Unuaire : public Expression
        {
        public:
            Unuaire(const binaire::SmartPtr<Expression> &x);

        protected:
            binaire::SmartPtr<Expression> m_x = {};
        };

        class Binaire : public Expression
        {
        public:
            Binaire() = default;
            Binaire(const binaire::SmartPtr<Expression> &a, const binaire::SmartPtr<Expression> &b);

        protected:
            binaire::SmartPtr<Expression> m_a = {};
            binaire::SmartPtr<Expression> m_b = {};
        };
    }
}
