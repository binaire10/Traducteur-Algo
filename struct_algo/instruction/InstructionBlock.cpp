#include "InstructionBlock.h"
#include "../interface/IInstructionVisitor.h"

InstructionBlock::InstructionBlock()
{}

void InstructionBlock::visiteInstruction(IInstructionVisitor &v) const
{
    v.visiteInstruction(*this);
}

InstructionBlock::iterator_instruction InstructionBlock::begin()
{
    return m_instructions.begin();
}

InstructionBlock::const_iterator_instruction InstructionBlock::begin() const
{
    return m_instructions.begin();
}

InstructionBlock::iterator_instruction InstructionBlock::end()
{
    return m_instructions.end();
}

InstructionBlock::const_iterator_instruction InstructionBlock::end() const
{
    return m_instructions.end();
}

InstructionBlock::iterator_instruction InstructionBlock::insert(const InstructionBlock::iterator_instruction &at, const std::shared_ptr<Instruction> &instruction)
{
    return m_instructions.insert(at, instruction);
}

void InstructionBlock::push_front(const std::shared_ptr<Instruction> &instruction)
{
    m_instructions.push_front(instruction);
}

void InstructionBlock::push_back(const std::shared_ptr<Instruction> &instruction)
{
    m_instructions.push_back(instruction);
}
