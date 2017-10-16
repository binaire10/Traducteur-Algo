#ifndef TRADUCTEUR_ALGO_LOOP_H
#define TRADUCTEUR_ALGO_LOOP_H

#include <memory>
#include "../interface/Instructable.h"
#include "../interface/Loopable.h"

class Loop : public Loopable
{
public:
    Loop(const std::shared_ptr<Instructable> &instruction) noexcept;
    void visiteInstruction(IInstructionVisitor &visitor) const override;
};

#endif //TRADUCTEUR_ALGO_LOOP_H
