#ifndef TRADUCTEUR_ALGO_BREAKLOOP_H
#define TRADUCTEUR_ALGO_BREAKLOOP_H

#include "../interface/Instructable.h"

class BreakLoop : public Instructable
{
public:
    void visiteInstruction(IInstructionVisitor &visitor) const override;
};

#endif //TRADUCTEUR_ALGO_BREAKLOOP_H
