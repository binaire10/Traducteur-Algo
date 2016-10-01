#pragma once
#include "InstructionBlock.h"
#include "Expression.h"


namespace ElementAlgorithmique
{
    class ConditionIf : public InstructionBlock
    {
    public:
        ConditionIf(const binaire::SmartPtr<Expression> &exp);
        ~ConditionIf() noexcept;
        ConditionIf(const ConditionIf &) = delete;
        ConditionIf &operator=(const ConditionIf &) = delete;
        ConditionIf *ElseIf(const binaire::SmartPtr<Expression> &exp);
        ConditionIf * Else();

        // InstructionInfo interface
    public:
        void ToCppCode(std::ostream &) override;
    private:
        ConditionIf(const binaire::SmartPtr<Expression> &exp, bool hasCondition);
        binaire::SmartPtr<Expression> m_exp;
        ConditionIf *m_else;
        bool m_SubCondition;
        bool m_hasCondition;
    };
}
