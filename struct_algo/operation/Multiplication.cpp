#include "Multiplication.h"
#include "../interface/AbstractOperationVisitor.h"

void Multiplication::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

std::shared_ptr<Multiplication> Multiplication::getInstance() noexcept
{
    static std::shared_ptr<Multiplication> instance = std::make_shared<Multiplication>(Multiplication());
    return instance;
}
