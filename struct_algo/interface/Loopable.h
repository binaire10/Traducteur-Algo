#ifndef LOOPABLE_H
#define LOOPABLE_H

#include "Instruction.h"
#include <memory>

class Loopable : public Instruction
{
public:
    std::shared_ptr<Instruction> instruction() const noexcept;

protected:
    Loopable(const std::shared_ptr<Instruction> &instruction) noexcept;
    std::shared_ptr<Instruction> m_instruction;
};

#endif // LOOPABLE_H
