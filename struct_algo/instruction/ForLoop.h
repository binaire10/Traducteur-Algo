#ifndef TRADUCTEUR_ALGO_FORLOOP_H
#define TRADUCTEUR_ALGO_FORLOOP_H

#include <memory>
#include "../interface/Instruction.h"
#include "../interface/Expression.h"
#include "../interface/Loopable.h"

class ForLoop : public Loopable
{
public:
    ForLoop(const std::shared_ptr<Expression> &whileCondition, const std::shared_ptr<Instruction> &instruction, const std::shared_ptr<Instruction> &afterEachLoop) noexcept;
    void visiteInstruction(IInstructionVisitor &visitor) const override;
    std::shared_ptr<Expression> whileCondition() const;
    std::shared_ptr<Instruction> afterEachLoop() const;

private:
    std::shared_ptr<Expression> m_whileCondition;
    std::shared_ptr<Instruction> m_afterEachLoop;
};

#endif //TRADUCTEUR_ALGO_FORLOOP_H
