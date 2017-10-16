#ifndef TRADUCTEUR_ALGO_NEXTLOOP_H
#define TRADUCTEUR_ALGO_NEXTLOOP_H

#include "../interface/LoopInstruction.h"


class NextLoop : public LoopInstruction
{
public:
    NextLoop(const std::shared_ptr<Loopable> &loop) noexcept;
    void visiteInstruction(IInstructionVisitor &visitor) const override;
};

#endif //TRADUCTEUR_ALGO_NEXTLOOP_H
