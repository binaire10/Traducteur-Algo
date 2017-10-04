#include "Multiplication.h"
#include "../interface/IOperationVisitor.h"

void Multiplication::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

std::shared_ptr<Multiplication> Multiplication::getInstance() noexcept
{
    static std::shared_ptr<Multiplication> instance = std::make_shared<Multiplication>(Multiplication());
    return instance;
}
