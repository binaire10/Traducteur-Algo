#ifndef TRADUCTEUR_ALGO_FORLOOP_H
#define TRADUCTEUR_ALGO_FORLOOP_H

#include "../interface/Instructable.h"

class ForLoop : public Instructable
{
public:
    void visiteInstruction(IInstructionVisitor &visitor) const override;
};

#endif //TRADUCTEUR_ALGO_FORLOOP_H
