#include "Multiplication.h"
#include "../interface/IOperationVisitor.h"
#include "../interface/IOperatorVisitor.h"

void Multiplication::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Multiplication::visiteOperator(IOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}

std::shared_ptr<Multiplication> Multiplication::getInstance() noexcept
{
    static std::shared_ptr<Multiplication> instance = std::make_shared<Multiplication>(Multiplication());
    return instance;
}
