#ifndef TRADUCTEUR_ALGO_CONDITIONAL_H
#define TRADUCTEUR_ALGO_CONDITIONAL_H

#include "../interface/Instructable.h"

class Conditional : public Instructable
{
public:
    void visiteInstruction(IInstructionVisitor &visitor) const override;
};

#endif //TRADUCTEUR_ALGO_CONDITIONAL_H
