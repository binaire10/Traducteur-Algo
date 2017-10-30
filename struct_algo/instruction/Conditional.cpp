#include "Conditional.h"
#include "../interface/IInstructionVisitor.h"

Conditional::Conditional(const std::shared_ptr<Expression> &condition, const std::shared_ptr<Instruction> &instruction, const std::shared_ptr<Instruction> &elseInstruction) noexcept : m_condition(condition), m_intruction(instruction), m_elseInstruction(elseInstruction)
{}

void Conditional::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}

std::shared_ptr<Expression> Conditional::condition() const noexcept
{
    return m_condition;
}

std::shared_ptr<Instruction> Conditional::intruction() const noexcept
{
    return m_intruction;
}

std::shared_ptr<Instruction> Conditional::elseInstruction() const noexcept
{
    return m_elseInstruction;
}
