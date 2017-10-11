#ifndef NOT_H
#define NOT_H

#include "LogicOperation.h"
#include "BitWiseOperation.h"

namespace BitWise
{
    class Not : public BitWiseOperation
    {
    public:
        static std::shared_ptr<Not> getInstance() noexcept;
        void visiteOperation(AbstractOperationVisitor &) const override;

    protected:
        constexpr Not() noexcept : BitWiseOperation(1)
        {}
    };
}
namespace Logic
{
    class Not : public LogicOperation
    {
    public:
        static std::shared_ptr<Not> getInstance() noexcept;
        void visiteOperation(AbstractOperationVisitor &) const override;

    protected:
        constexpr Not() noexcept : LogicOperation(1)
        {}
    };
}

#endif // NOT_H
