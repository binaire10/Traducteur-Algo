#include "Type.h"
#include "../interface/ICommonType.h"

Type::Type(const std::shared_ptr<ICommonType> &ptr, unsigned pointerLevel, bool isConst, bool isReference) noexcept : d_ptr(ptr), m_pointerLevel(pointerLevel), m_isConst(isConst), m_isReference(isReference)
{}

std::size_t Type::hashType() const noexcept
{
    return d_ptr->hashType();
}

std::string Type::name() const noexcept
{
    return d_ptr->name();
}

bool Type::equals(const Type &value) const noexcept
{
    return value.m_isConst == m_isConst && value.m_isReference == m_isReference && value.m_pointerLevel == m_pointerLevel && d_ptr->equals(*value.d_ptr.get());
}

bool Type::isConvertible(const Type &value) const noexcept
{
    return value.m_pointerLevel == m_pointerLevel && d_ptr->convertible(*value.d_ptr.get());
}

bool Type::operator ==(const Type &t) const noexcept
{
    return equals(t);
}

bool Type::operator !=(const Type &t) const noexcept
{
    return !equals(t);
}

void Type::visite(ICommonTypeVisitor &v)
{
    d_ptr->visiteCommonType(v);
}

std::size_t Type::sizeType() const noexcept
{
    return d_ptr->size();
}
