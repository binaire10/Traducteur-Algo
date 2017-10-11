#include "Division.h"
#include "../interface/AbstractOperationVisitor.h"

void Division::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

std::shared_ptr<Division> Division::getInstance() noexcept
{
    static std::shared_ptr<Division> instance = std::make_shared<Division>(Division());
    return instance;
}
