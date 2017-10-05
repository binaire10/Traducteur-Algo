#include "Division.h"
#include "../interface/IOperationVisitor.h"
#include "../interface/IOperatorVisitor.h"

void Division::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Division::visiteOperator(IOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}

std::shared_ptr<Division> Division::getInstance() noexcept
{
    static std::shared_ptr<Division> instance = std::make_shared<Division>(Division());
    return instance;
}
