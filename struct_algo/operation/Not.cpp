#include "Not.h"
#include "../interface/AbstractOperationVisitor.h"

std::shared_ptr<Logic::Not> Logic::Not::getInstance() noexcept
{
    static std::shared_ptr<Not> instance = std::make_shared<Not>(Not());
    return instance;
}

void Logic::Not::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

std::shared_ptr<BitWise::Not> BitWise::Not::getInstance() noexcept
{
    static std::shared_ptr<Not> instance = std::make_shared<Not>(Not());
    return instance;
}

void BitWise::Not::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}
