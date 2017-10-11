#ifndef OR_H
#define OR_H

#include "LogicOperation.h"
#include "BitWiseOperation.h"

namespace BitWise
{
    class Or : public BitWiseOperation
    {
    public:
        static std::shared_ptr<Or> getInstance() noexcept;
        void visiteOperation(AbstractOperationVisitor &) const override;

    protected:
        constexpr Or() noexcept : BitWiseOperation(2)
        {}
    };
}
namespace Logic
{
    class Or : public LogicOperation
    {
    public:
        static std::shared_ptr<Or> getInstance() noexcept;
        void visiteOperation(AbstractOperationVisitor &) const override;

    protected:
        constexpr Or() noexcept : LogicOperation(2)
        {}
    };
}

#endif // OR_H
