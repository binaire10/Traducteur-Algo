#ifndef TRADUCTEUR_ALGO_CONDITIONAL_H
#define TRADUCTEUR_ALGO_CONDITIONAL_H

#include "../interface/Instructable.h"
#include "../interface/Expressionable.h"

class Conditional : public Instructable
{
public:
    Conditional(const std::shared_ptr<Expressionable> &condition, const std::shared_ptr<Instructable> &instruction, const std::shared_ptr<Instructable> &elseInstruction) noexcept;
    void visiteInstruction(IInstructionVisitor &visitor) const override;
    std::shared_ptr<Expressionable> condition() const noexcept;
    std::shared_ptr<Instructable> intruction() const noexcept;
    std::shared_ptr<Instructable> elseInstruction() const noexcept;

private:
    std::shared_ptr<Expressionable> m_condition;
    std::shared_ptr<Instructable> m_intruction;
    std::shared_ptr<Instructable> m_elseInstruction;
};

#endif //TRADUCTEUR_ALGO_CONDITIONAL_H
