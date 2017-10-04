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
        void visiteOperation(IOperationVisitor &) const override;

    protected:
        constexpr Not() = default;
    };
}
namespace Logic
{
    class Not : public LogicOperation
    {
    public:
        static std::shared_ptr<Not> getInstance() noexcept;
        void visiteOperation(IOperationVisitor &) const override;

    protected:
        constexpr Not() = default;
    };
}

#endif // NOT_H
