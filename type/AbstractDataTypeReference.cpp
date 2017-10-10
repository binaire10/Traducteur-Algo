#include "AbstractDataTypeReference.h"
#include <map>
#include "ConstAbstractDataType.h"
#include "../interface/AbstractDataTypeVisitor.h"

AbstractDataTypeReference::AbstractDataTypeReference(const std::shared_ptr<AbstractDataType> &internalType) : AbstractDataType(std::hash<std::string>()("AbstractDataTypeReference"), internalType->size()), m_internalType(internalType)
{
    if(m_internalType->instanceOf<AbstractDataTypeReference>())
        throw std::runtime_error("modificator cannot be applied on reference type");
    if(m_internalType->instanceOf<ConstAbstractDataType>())
        throw std::runtime_error("modificator cannot be applied on const type");
}

bool AbstractDataTypeReference::equals(const AbstractDataType &c) const noexcept
{
    const AbstractDataTypeReference *ptr = dynamic_cast<const AbstractDataTypeReference *>(&c);
    return ptr && m_internalType->equals(*ptr->m_internalType);
}

bool AbstractDataTypeReference::isConvertible(const AbstractDataType &c) const noexcept
{
    const AbstractDataTypeReference *ptr = dynamic_cast<const AbstractDataTypeReference *>(&c);
    const AbstractDataType *realType = ptr ? ptr->m_internalType.get():&c;

    return realType && m_internalType->isConvertible(*realType);
}

void AbstractDataTypeReference::visiteType(AbstractDataTypeVisitor &v) const
{
    v.visiteType(*this);
}

std::shared_ptr<AbstractDataType> AbstractDataTypeReference::internalType() const noexcept
{
    return m_internalType;
}
