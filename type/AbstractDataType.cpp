#include "AbstractDataType.h"
#include "../interface/ICommonAbstractData.h"

AbstractDataType::AbstractDataType(const std::shared_ptr<ICommonAbstractData> &ptr, unsigned pointerLevel, bool isConst, bool isReference) noexcept : d_ptr(ptr), m_pointerLevel(pointerLevel), m_isConst(isConst), m_isReference(isReference)
{}

std::size_t AbstractDataType::hashType() const noexcept
{
    return d_ptr->hashType();
}

std::string AbstractDataType::name() const noexcept
{
    return d_ptr->name();
}

bool AbstractDataType::equals(const AbstractDataType &value) const noexcept
{
    return value.m_isConst == m_isConst && value.m_isReference == m_isReference && value.m_pointerLevel == m_pointerLevel && d_ptr->equals(*value.d_ptr.get());
}

bool AbstractDataType::isConvertible(const AbstractDataType &value) const noexcept
{
    return value.m_pointerLevel == m_pointerLevel && d_ptr->convertible(*value.d_ptr.get());
}

bool AbstractDataType::operator ==(const AbstractDataType &t) const noexcept
{
    return equals(t);
}

bool AbstractDataType::operator !=(const AbstractDataType &t) const noexcept
{
    return !equals(t);
}

void AbstractDataType::visite(ICommonAbstractDataVisitor &v)
{
    d_ptr->visiteCommonType(v);
}

std::size_t AbstractDataType::sizeType() const noexcept
{
    return d_ptr->size();
}
