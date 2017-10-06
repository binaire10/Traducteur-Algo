#include "Or.h"
#include "../interface/AbstractOperationVisitor.h"
#include "../interface/AbstractOperatorVisitor.h"

std::shared_ptr<Logic::Or> Logic::Or::getInstance() noexcept
{
    static std::shared_ptr<Or> instance = std::make_shared<Or>(Or());
    return instance;
}

void Logic::Or::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Logic::Or::visiteOperator(AbstractOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}

std::shared_ptr<BitWise::Or> BitWise::Or::getInstance() noexcept
{
    static std::shared_ptr<Or> instance = std::make_shared<Or>(Or());
    return instance;
}

void BitWise::Or::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void BitWise::Or::visiteOperator(AbstractOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}
