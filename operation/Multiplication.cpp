#include "Multiplication.h"
#include "../interface/AbstractOperationVisitor.h"
#include "../interface/AbstractOperatorVisitor.h"

void Multiplication::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Multiplication::visiteOperator(AbstractOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}

std::shared_ptr<Multiplication> Multiplication::getInstance() noexcept
{
    static std::shared_ptr<Multiplication> instance = std::make_shared<Multiplication>(Multiplication());
    return instance;
}
