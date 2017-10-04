#ifndef INSTRUCTIONBLOCK_H
#define INSTRUCTIONBLOCK_H

#include <list>
#include <memory>
#include "../interface/IInstruction.h"

class InstructionBlock : public IInstruction
{
public:
    using iterator_instruction = std::list<std::shared_ptr<IInstruction>>::iterator;
    using const_iterator_instruction = std::list<std::shared_ptr<IInstruction>>::const_iterator;
    InstructionBlock();
    void visiteInstruction(IInstructionVisitor &) const override;
    iterator_instruction begin();
    const_iterator_instruction begin() const;
    iterator_instruction end();
    const_iterator_instruction end() const;
    iterator_instruction insert(const iterator_instruction &at, const std::shared_ptr<IInstruction> &data);
    void push_front(const std::shared_ptr<IInstruction> &data);
    void push_back(const std::shared_ptr<IInstruction> &data);

private:
    std::list<std::shared_ptr<IInstruction>> m_instructions;
};

#endif // INSTRUCTIONBLOCK_H
