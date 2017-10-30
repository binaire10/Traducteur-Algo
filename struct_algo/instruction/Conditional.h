#ifndef TRADUCTEUR_ALGO_CONDITIONAL_H
#define TRADUCTEUR_ALGO_CONDITIONAL_H

#include "../interface/Instruction.h"
#include "../interface/Expression.h"

class Conditional : public Instruction
{
public:
    Conditional(const std::shared_ptr<Expression> &condition, const std::shared_ptr<Instruction> &instruction, const std::shared_ptr<Instruction> &elseInstruction) noexcept;
    void visiteInstruction(IInstructionVisitor &visitor) const override;
    std::shared_ptr<Expression> condition() const noexcept;
    std::shared_ptr<Instruction> intruction() const noexcept;
    std::shared_ptr<Instruction> elseInstruction() const noexcept;

private:
    std::shared_ptr<Expression> m_condition;
    std::shared_ptr<Instruction> m_intruction;
    std::shared_ptr<Instruction> m_elseInstruction;
};

#endif //TRADUCTEUR_ALGO_CONDITIONAL_H
