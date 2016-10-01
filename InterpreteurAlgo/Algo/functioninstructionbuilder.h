#pragma once
#include "LecteurCode.h"


class FunctionInstructionBuilder : public ElementAlgorithmique::LecteurCode::InstructionGenerator
{
public:
    FunctionInstructionBuilder(ElementAlgorithmique::LecteurCode *code);
    bool valideInstruction(const StringRef &) const noexcept override;
    void buildInstructionFromAlgo(const StringRef &InstructionName, binaire::LexicalParseur &GlobalParseur, binaire::SmartPtr<ElementAlgorithmique::InstructionBlock> &impl, ElementAlgorithmique::Fonction *currentFonc, ElementAlgorithmique::BaseLoop *currentLoop) override;
};
