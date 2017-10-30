#include "Loopable.h"

Loopable::Loopable(const std::shared_ptr<Instruction> &instruction) noexcept : m_instruction(instruction)
{

}

std::shared_ptr<Instruction> Loopable::instruction() const noexcept
{
    return m_instruction;
}
