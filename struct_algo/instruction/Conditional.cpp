#include "Conditional.h"
#include "../interface/IInstructionVisitor.h"

Conditional::Conditional(const std::shared_ptr<Expressionable> &condition, const std::shared_ptr<Instructable> &instruction, const std::shared_ptr<Instructable> &elseInstruction) noexcept : m_condition(condition), m_intruction(instruction), m_elseInstruction(elseInstruction)
{}

void Conditional::visiteInstruction(IInstructionVisitor &visitor) const
{
    visitor.visiteInstruction(*this);
}

std::shared_ptr<Expressionable> Conditional::condition() const noexcept
{
    return m_condition;
}

std::shared_ptr<Instructable> Conditional::intruction() const noexcept
{
    return m_intruction;
}

std::shared_ptr<Instructable> Conditional::elseInstruction() const noexcept
{
    return m_elseInstruction;
}
