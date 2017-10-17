#include "NumericDataType.h"
#include <map>
#include "../interface/AbstractDataTypeVisitor.h"

std::shared_ptr<NumericDataType> NumericDataType::getInstance(NumericDataType::NumericType type) noexcept
{
    static std::map<NumericType, std::shared_ptr<NumericDataType>> instance;
    std::map<NumericType, std::shared_ptr<NumericDataType>>::const_iterator it = instance.find(type);
    if(instance.end() == it)
    {
        std::shared_ptr<NumericDataType> value = std::make_shared<NumericDataType>(NumericDataType(type));
        instance.insert({type, value});
        return value;
    }
    return it->second;
}

bool NumericDataType::equals(const AbstractDataType &c) const noexcept
{
    const NumericDataType *ptr = dynamic_cast<const NumericDataType *>(&c);
    return ptr && (ptr->m_type == m_type);
}

void NumericDataType::visiteType(AbstractDataTypeVisitor &v) const
{
    v.visiteType(*this);
}

NumericDataType::NumericDataType(NumericDataType::NumericType t) : ScalarDataType(toScalarType(t)), m_type(t)
{}

NumericDataType::NumericType NumericDataType::getType() const
{
    return m_type;
}
