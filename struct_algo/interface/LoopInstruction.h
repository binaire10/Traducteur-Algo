#ifndef LOOPINSTRUCTION_H
#define LOOPINSTRUCTION_H

#include <memory>
#include "Instructable.h"
#include "Loopable.h"

class LoopInstruction : public Instructable
{
public:
    LoopInstruction(const std::shared_ptr<Loopable> &loop) noexcept;
    std::shared_ptr<Loopable> loop() const noexcept;

private:
    std::shared_ptr<Loopable> m_loop;
};

#endif // LOOPINSTRUCTION_H
