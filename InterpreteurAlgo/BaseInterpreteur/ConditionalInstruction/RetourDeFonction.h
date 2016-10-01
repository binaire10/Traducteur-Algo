#pragma once
#include "InstructionBlock.h"
#include "Expression.h"
#include "Fonction.h"


namespace ElementAlgorithmique
{
    class RetourDeFonction : public Instruction
    {
    public:
        RetourDeFonction(Fonction *block);
        RetourDeFonction(Fonction *block, const binaire::SmartPtr<Expression> &);
        RetourDeFonction(const RetourDeFonction &) = delete;
        RetourDeFonction &operator=(const RetourDeFonction &) = delete;

    private:
        bool m_ValueReturn;
        Fonction *m_block;
        binaire::SmartPtr<Expression> m_exp;

        // InstructionInfo interface
    public:
        void ToCppCode(std::ostream &) override;
    };
}
