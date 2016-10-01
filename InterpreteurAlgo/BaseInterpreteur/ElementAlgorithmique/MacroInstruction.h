#pragma once
#include "Instruction.h"

namespace ElementAlgorithmique
{
    class MacroInstruction : public Instruction
    {
    public:
        MacroInstruction() = default;
        MacroInstruction(const MacroInstruction &) = delete;
        MacroInstruction &operator=(const MacroInstruction &) = delete;
        void ToCppCode(std::ostream &) override;
        void setCppCode(const std::string &CppCode) noexcept;

    private:
        std::string m_CppCode = std::string();
    };
}
