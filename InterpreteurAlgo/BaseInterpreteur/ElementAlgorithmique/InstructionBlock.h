#pragma once
#include <list>
#include <ostream>
#include <MyMemory/SmartPtr.hpp>
#include "Instruction.h"
#include "VariablePrototype.h"

namespace ElementAlgorithmique
{
    /**
     * @brief The InstructionBlock class
     */
    class InstructionBlock : public Instruction
    {
    public:
        InstructionBlock() = default;
        InstructionBlock(const std::list< binaire::SmartPtr<Instruction> > &inst) noexcept;
        InstructionBlock(const InstructionBlock &) = delete;
        InstructionBlock &operator=(const InstructionBlock &) = delete;
        void ToCppCode(std::ostream &os) override;

        /**
         * @brief getInstructionList
         * Permet de récupérer modifier les Instruction contenue dans le block
         * @return
         */
        std::list<binaire::SmartPtr<Instruction> > &getInstructionList();

        /**
         * @brief getInstructionList
         * Permet de récupérer les Instructions contenue dans le block
         * @return
         */
        const std::list<binaire::SmartPtr<Instruction> > &getInstructionList() const;

        /**
         * @brief getVariableContexte
         * Permet de récupérer les variables Contenue dans le Block
         * @return
         */
        const std::list<VariablePrototype> &getVariableContexte() const;

        /**
         * @brief getVariableContexte
         * Permet de récupérer ou modifier les variables Contenue dans le Block
         * @return
         */
        std::list<VariablePrototype> &getVariableContexte();

    private:
        std::list< binaire::SmartPtr<Instruction> > m_InstructionList = std::list< binaire::SmartPtr<Instruction> >();
        std::list<VariablePrototype> m_VariableContexte = std::list<VariablePrototype>();
    };
}
