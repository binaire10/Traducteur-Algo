#pragma once
#include "BaseLoop.h"


namespace ElementAlgorithmique
{
    class Loop : public BaseLoop
    {
    public:
        Loop() = default;
    private:

        // InstructionInfo interface
    public:
        void ToCppCode(std::ostream &) override;
    };
}
