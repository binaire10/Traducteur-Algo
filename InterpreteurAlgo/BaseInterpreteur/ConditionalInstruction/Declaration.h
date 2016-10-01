#pragma once
#include <string>
#include "VariablePrototype.h"
#include "Instruction.h"

namespace ElementAlgorithmique
{
    class Declaration : public Instruction
    {
    public:
        Declaration(VariablePrototype *Var);
        Declaration(const Declaration &) = delete;
        Declaration &operator=(const Declaration &) = delete;
        void ToCppCode(std::ostream &Result) override;
    private:
        VariablePrototype *VarName;
    };
}
