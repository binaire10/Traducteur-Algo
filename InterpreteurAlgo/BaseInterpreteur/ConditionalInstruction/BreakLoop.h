#pragma once
#include "BaseLoop.h"


namespace ElementAlgorithmique
{
    class BreakLoop : public Instruction
    {
    public:
        BreakLoop(BaseLoop *current);
        BreakLoop(const BreakLoop &) = delete;
        BreakLoop &operator =(const BreakLoop &) = delete;

    private:
        BaseLoop *m_loop;

        // InstructionInfo interface
    public:
        void ToCppCode(std::ostream &) override;
    };
}
