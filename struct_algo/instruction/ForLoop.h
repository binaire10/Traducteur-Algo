#ifndef TRADUCTEUR_ALGO_FORLOOP_H
#define TRADUCTEUR_ALGO_FORLOOP_H

#include <memory>
#include "../interface/Instructable.h"
#include "../interface/Expressionable.h"
#include "../interface/Loopable.h"

class ForLoop : public Loopable
{
public:
    ForLoop(const std::shared_ptr<Expressionable> &whileCondition, const std::shared_ptr<Instructable> &instruction, const std::shared_ptr<Instructable> &afterEachLoop) noexcept;
    void visiteInstruction(IInstructionVisitor &visitor) const override;
    std::shared_ptr<Expressionable> whileCondition() const;
    std::shared_ptr<Instructable> afterEachLoop() const;

private:
    std::shared_ptr<Expressionable> m_whileCondition;
    std::shared_ptr<Instructable> m_afterEachLoop;
};

#endif //TRADUCTEUR_ALGO_FORLOOP_H
