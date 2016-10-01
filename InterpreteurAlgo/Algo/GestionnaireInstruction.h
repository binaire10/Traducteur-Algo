#pragma once
#include <list>
#include "struccore.h"
#include "LecteurCode.h"

class GestionnaireInstruction
{
public:
    GestionnaireInstruction() = default;
    bool findDecodeur(const StringRef &) const noexcept;
    ElementAlgorithmique::LecteurCode::InstructionGenerator *getDecodeur(const StringRef &);
    void addDecodeur(ElementAlgorithmique::LecteurCode::InstructionGenerator *) noexcept;

private:
    std::list<ElementAlgorithmique::LecteurCode::InstructionGenerator *> m_Decodeur = {};
};
