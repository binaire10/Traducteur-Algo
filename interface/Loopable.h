#ifndef LOOPABLE_H
#define LOOPABLE_H

#include "Instructable.h"
#include <memory>

class Loopable : public Instructable
{
public:
    std::shared_ptr<Instructable> instruction() const noexcept;

protected:
    Loopable(const std::shared_ptr<Instructable> &instruction) noexcept;
    std::shared_ptr<Instructable> m_instruction;
};

#endif // LOOPABLE_H
