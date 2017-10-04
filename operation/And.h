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
    protected:
        constexpr And() noexcept = default;
    };
}
namespace Logic
{
    class And : public LogicOperation
    {
    public:
        void visiteOperation(IOperationVisitor &) const override;
        static std::shared_ptr<And> getInstance() noexcept;
    protected:
        constexpr And() noexcept = default;
    };
}

#endif // AND_H
