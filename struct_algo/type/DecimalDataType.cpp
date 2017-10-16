#include "DecimalDataType.h"
#include "../interface/AbstractDataTypeVisitor.h"

bool DecimalDataType::equals(const AbstractDataType &c) const noexcept
{
    const DecimalDataType *ptr = dynamic_cast<const DecimalDataType *>(&c);
    return ptr;
}

std::shared_ptr<DecimalDataType> DecimalDataType::getInstance() noexcept
{
    static std::shared_ptr<DecimalDataType> instance = std::make_shared<DecimalDataType>(DecimalDataType());
    return instance;
}

void DecimalDataType::visiteType(AbstractDataTypeVisitor &v) const
{
    v.visiteType(*this);
}

DecimalDataType::DecimalDataType() : ScalarDataType(std::hash<std::string>()("DecimalDataType"), 8)
{}
