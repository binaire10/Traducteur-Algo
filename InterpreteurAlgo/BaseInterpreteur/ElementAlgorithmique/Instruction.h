#pragma once
#include <ostream>

namespace ElementAlgorithmique
{
    /**
     * @brief The InstructionInfo class
     * Class Mére de toute les objets utilisable par le traducteur
     */
    class Instruction
    {
    public:
        Instruction() = default;
        virtual ~Instruction() = default;
        Instruction(const Instruction &) = delete;
        Instruction &operator =(const Instruction &) = delete;
        /**
     * @brief ToCppCode
     * Fonction virtuel permettant de tranformé n'importe quel instruction en code c++
     * @param os
     * Sortie de code en c++
     */
        virtual void ToCppCode(std::ostream &os) = 0;
    };
}
