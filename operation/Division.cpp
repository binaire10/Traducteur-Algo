#include "Division.h"
#include "../interface/AbstractOperationVisitor.h"
#include "../interface/AbstractOperatorVisitor.h"

void Division::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Division::visiteOperator(AbstractOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}

std::shared_ptr<Division> Division::getInstance() noexcept
{
    static std::shared_ptr<Division> instance = std::make_shared<Division>(Division());
    return instance;
}
