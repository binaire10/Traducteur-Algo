#include "Or.h"
#include "../interface/IOperationVisitor.h"
#include "../interface/IOperatorVisitor.h"

std::shared_ptr<Logic::Or> Logic::Or::getInstance() noexcept
{
    static std::shared_ptr<Or> instance = std::make_shared<Or>(Or());
    return instance;
}

void Logic::Or::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Logic::Or::visiteOperator(IOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}

std::shared_ptr<BitWise::Or> BitWise::Or::getInstance() noexcept
{
    static std::shared_ptr<Or> instance = std::make_shared<Or>(Or());
    return instance;
}

void BitWise::Or::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void BitWise::Or::visiteOperator(IOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}
