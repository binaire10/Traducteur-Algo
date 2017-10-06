#include "Substract.h"
#include "../interface/AbstractOperationVisitor.h"
#include "../interface/AbstractOperatorVisitor.h"

std::shared_ptr<Substract> Substract::getInstance() noexcept
{
    static std::shared_ptr<Substract> instance = std::make_shared<Substract>(Substract());
    return instance;
}

void Substract::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Substract::visiteOperator(AbstractOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}
