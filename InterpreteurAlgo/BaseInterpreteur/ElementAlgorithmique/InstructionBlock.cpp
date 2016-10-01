#include "InstructionBlock.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

InstructionBlock::InstructionBlock(const list<SmartPtr<Instruction> > &inst) noexcept : m_InstructionList(inst)
{}

void InstructionBlock::ToCppCode(std::ostream &result)
{
    // On indente le code pour que la sortie puisse être lisible par un humain
    ++Indentation;
    for(SmartPtr<Instruction> &i : m_InstructionList)
    {
        // On construit les instructions contenue dans le block du premier au dernié
        i->ToCppCode(result);
    }
    //Operation identique à la premiére
    --Indentation;
}

list<SmartPtr<Instruction> > &InstructionBlock::getInstructionList()
{
    return m_InstructionList;
}

const list<SmartPtr<Instruction> > & InstructionBlock::getInstructionList() const
{
    return m_InstructionList;
}

list<VariablePrototype> &InstructionBlock::getVariableContexte()
{
    return m_VariableContexte;
}

const list<VariablePrototype> &InstructionBlock::getVariableContexte() const
{
    return m_VariableContexte;
}
