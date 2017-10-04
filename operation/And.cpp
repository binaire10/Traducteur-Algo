#include "And.h"
#include "../interface/IOperationVisitor.h"

void Logic::And::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

std::shared_ptr<Logic::And> Logic::And::getInstance() noexcept
{
    static std::shared_ptr<Logic::And> instance = std::make_shared<Logic::And>(And());
    return instance;
}

void BitWise::And::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

std::shared_ptr<BitWise::And> BitWise::And::getInstance() noexcept
{
    static std::shared_ptr<BitWise::And> instance = std::make_shared<BitWise::And>(And());
    return instance;
}

