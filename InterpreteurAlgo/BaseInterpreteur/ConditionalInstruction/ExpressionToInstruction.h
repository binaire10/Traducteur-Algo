#pragma once
#include <ostream>
#include <MyMemory/SmartPtr.hpp>
#include "Expression.h"
#include "VariablePrototype.h"
#include "Instruction.h"

namespace ElementAlgorithmique
{
    class ExpressionToInstruction : public Instruction
    {
    public:
        ExpressionToInstruction(const binaire::SmartPtr<Expression> &a);
        void ToCppCode(std::ostream &Result) override;
        binaire::SmartPtr<Expression> Exp;
    };
}
