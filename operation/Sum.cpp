#include "Sum.h"
#include "../interface/AbstractOperationVisitor.h"
#include "../interface/AbstractOperatorVisitor.h"

std::shared_ptr<Sum> Sum::getInstance() noexcept
{
    static std::shared_ptr<Sum> instance = std::make_shared<Sum>(Sum());
    return instance;
}

void Sum::visiteOperation(AbstractOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void Sum::visiteOperator(AbstractOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}
