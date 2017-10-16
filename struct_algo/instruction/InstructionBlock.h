#ifndef INSTRUCTIONBLOCK_H
#define INSTRUCTIONBLOCK_H

#include <list>
#include <memory>
#include "../interface/Instructable.h"

class InstructionBlock : public Instructable
{
public:
    using iterator_instruction = std::list<std::shared_ptr<Instructable>>::iterator;
    using const_iterator_instruction = std::list<std::shared_ptr<Instructable>>::const_iterator;
    InstructionBlock();
    void visiteInstruction(IInstructionVisitor &) const override;
    iterator_instruction begin();
    const_iterator_instruction begin() const;
    iterator_instruction end();
    const_iterator_instruction end() const;
    iterator_instruction insert(const iterator_instruction &at, const std::shared_ptr<Instructable> &data);
    void push_front(const std::shared_ptr<Instructable> &data);
    void push_back(const std::shared_ptr<Instructable> &data);

private:
    std::list<std::shared_ptr<Instructable>> m_instructions;
};

#endif // INSTRUCTIONBLOCK_H
