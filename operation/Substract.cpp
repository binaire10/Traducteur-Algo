#include "Substract.h"
#include "../interface/IOperationVisitor.h"

std::shared_ptr<Substract> Substract::getInstance() noexcept
{
    static std::shared_ptr<Substract> instance = std::make_shared<Substract>(Substract());
    return instance;
}

void Substract::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}
