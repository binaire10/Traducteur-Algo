#include "Sum.h"
#include "../type/CommonScalar.h"
#include "../interface/IOperationVisitor.h"
#include "../interface/IOperatorVisitor.h"

std::shared_ptr<Sum> Sum::getInstance() noexcept
{
    static std::shared_ptr<Sum> instance = std::make_shared<Sum>(Sum());
    return instance;
}

void Sum::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Sum::visiteOperator(IOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}
