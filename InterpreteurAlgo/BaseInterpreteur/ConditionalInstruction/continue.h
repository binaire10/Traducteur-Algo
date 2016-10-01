#pragma once
#include "Instruction.h"
#include "BaseLoop.h"


namespace ElementAlgorithmique
{
    class Continue : public Instruction
    {
    public:
        Continue() = delete;
        Continue(const Continue &) = delete;
        Continue operator=(const Continue &) = delete;
        Continue(BaseLoop *loop);
        void ToCppCode(std::ostream &os) override;
    private:
        BaseLoop *m_Target;
    };
}
