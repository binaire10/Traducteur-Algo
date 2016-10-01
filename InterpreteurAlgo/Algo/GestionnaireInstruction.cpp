#include "GestionnaireInstruction.h"
#include <stdexcept>

using namespace std;
using namespace ElementAlgorithmique;
using namespace InstructionAvance;

bool GestionnaireInstruction::findDecodeur(const StringRef &Inst) const noexcept
{
    for(const LecteurCode::InstructionGenerator * const &i : m_Decodeur)
        if(i->valideInstruction(Inst))
            return true;
    return false;
}

LecteurCode::InstructionGenerator *GestionnaireInstruction::getDecodeur(const StringRef &Inst)
{
    for(LecteurCode::InstructionGenerator *&i : m_Decodeur)
        if(i->valideInstruction(Inst))
            return i;
    throw runtime_error("Decodeur non trouver");
}

void GestionnaireInstruction::addDecodeur(LecteurCode::InstructionGenerator *Value) noexcept
{
    m_Decodeur.push_back(Value);
}
