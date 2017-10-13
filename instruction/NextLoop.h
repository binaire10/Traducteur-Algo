#ifndef TRADUCTEUR_ALGO_NEXTLOOP_H
#define TRADUCTEUR_ALGO_NEXTLOOP_H

#include "../interface/Instructable.h"

class NextLoop : public Instructable
{
public:
    void visiteInstruction(IInstructionVisitor &visitor) const override;
};

#endif //TRADUCTEUR_ALGO_NEXTLOOP_H
