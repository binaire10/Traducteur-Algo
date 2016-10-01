#pragma once
#include "InstructionBlock.h"


namespace ElementAlgorithmique
{
    /**
     * @brief The BaseLoop class
     * Base de toute les autres objet qui permettent de crée des boucles
     */
    class BaseLoop : public InstructionBlock
    {
    public:
        BaseLoop() = default;
        /**
         * @brief BaseLoop
         * Permet au objet fille de d'initialiser des instructions
         * @param inst
         */
        BaseLoop(const std::list<binaire::SmartPtr<Instruction> > &inst) noexcept;
    };
}
