#pragma once
#include "LecteurCode.h"


class LoopBuilder : public ElementAlgorithmique::LecteurCode::InstructionGenerator
{
public:
    LoopBuilder(ElementAlgorithmique::LecteurCode *code);
    bool valideInstruction(const StringRef &InstructionName) const noexcept override;
    void buildInstructionFromAlgo(const StringRef &InstructionName, binaire::LexicalParseur &Parseur, binaire::SmartPtr<ElementAlgorithmique::InstructionBlock> &impl, ElementAlgorithmique::Fonction *currentFonc, ElementAlgorithmique::BaseLoop *currentLoop) override;

private:
};
