#include "Loopable.h"

Loopable::Loopable(const std::shared_ptr<Instructable> &instruction) noexcept : m_instruction(instruction)
{

}

std::shared_ptr<Instructable> Loopable::instruction() const noexcept
{
    return m_instruction;
}
