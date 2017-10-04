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
        void visiteOperation(IOperationVisitor &) const override;

    protected:
        constexpr Or() = default;
    };
}
namespace Logic
{
    class Or : public LogicOperation
    {
    public:
        static std::shared_ptr<Or> getInstance() noexcept;
        void visiteOperation(IOperationVisitor &) const override;

    protected:
        constexpr Or() = default;
    };
}

#endif // OR_H