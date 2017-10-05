#ifndef AND_H
#define AND_H

#include "LogicOperation.h"
#include "BitWiseOperation.h"

namespace BitWise
{
    class And : public BitWiseOperation
    {
    public:
        void visiteOperation(IOperationVisitor &) const override;
        static std::shared_ptr<And> getInstance() noexcept;
        void visiteOperator(IOperatorVisitor &) const override;

    protected:
        constexpr And() noexcept : BitWiseOperation(2)
        {}
    };
}
namespace Logic
{
    class And : public LogicOperation
    {
    public:
        void visiteOperation(IOperationVisitor &) const override;
        static std::shared_ptr<And> getInstance() noexcept;
        void visiteOperator(IOperatorVisitor &) const override;

    protected:
        constexpr And() noexcept  : LogicOperation(2)
        {}
    };
}

#endif // AND_H
