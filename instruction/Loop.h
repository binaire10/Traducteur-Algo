#ifndef TRADUCTEUR_ALGO_LOOP_H
#define TRADUCTEUR_ALGO_LOOP_H

#include "../interface/Instructable.h"

class Loop : public Instructable
{
public:
    void visiteInstruction(IInstructionVisitor &visitor) const override;
};

#endif //TRADUCTEUR_ALGO_LOOP_H
