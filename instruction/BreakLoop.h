#ifndef TRADUCTEUR_ALGO_BREAKLOOP_H
#define TRADUCTEUR_ALGO_BREAKLOOP_H

#include "../interface/LoopInstruction.h"

class BreakLoop : public LoopInstruction
{
public:
    BreakLoop(const std::shared_ptr<Loopable> &loop) noexcept;
    void visiteInstruction(IInstructionVisitor &visitor) const override;
};

#endif //TRADUCTEUR_ALGO_BREAKLOOP_H
