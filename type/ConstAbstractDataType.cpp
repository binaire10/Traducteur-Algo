#include "ConstAbstractDataType.h"
#include "AbstractDataTypeReference.h"
#include <map>
#include <cassert>
#include "../exception/BadModificator.h"

namespace
{
    const AbstractDataType *removeModificator(const AbstractDataType *ptr) noexcept
    {
        const ConstAbstractDataType *ConstType = dynamic_cast<const ConstAbstractDataType *>(ptr);
        const AbstractDataTypeReference *RefPtr = dynamic_cast<const AbstractDataTypeReference *>(ConstType->internalType().get());

        return RefPtr ? RefPtr->internalType().get() : (ConstType ? ConstType->internalType().get() : ptr);
    }
}

ConstAbstractDataType::ConstAbstractDataType(const std::shared_ptr<AbstractDataType> &internalType) : AbstractDataType(std::hash<std::string>()("ConstAbstractDataType") ^ (internalType->hash() << 1), internalType->size()), m_internalType(internalType)
{
    if(m_internalType->instanceOf<ConstAbstractDataType>())
        throw BadModificator("const cannot be applied on const type");
}

bool ConstAbstractDataType::equals(const AbstractDataType &c) const noexcept
{
    const ConstAbstractDataType *ptr = dynamic_cast<const ConstAbstractDataType *>(&c);
    return ptr && m_internalType->equals(*ptr->m_internalType);
}

bool ConstAbstractDataType::isConvertible(const AbstractDataType &c) const noexcept
{
    const AbstractDataType *realType = removeModificator(&c);
    assert(realType != nullptr);

    return realType && m_internalType->isConvertible(*realType);
}

void ConstAbstractDataType::visiteType(AbstractDataTypeVisitor &v) const
{
    v.visiteType(*this);
}

std::shared_ptr<AbstractDataType> ConstAbstractDataType::internalType() const noexcept
{
    return m_internalType;
}
