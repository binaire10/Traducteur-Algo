#ifndef ABSTRACTDATATYPE_H
#define ABSTRACTDATATYPE_H

#include <utility>
#include "../interface/AbstractDataTypeVisitor.h"

class AbstractDataType
{
public:
    constexpr AbstractDataType(std::size_t hash, std::size_t size) noexcept : m_hash(hash), m_size(size)
    {}
    virtual bool equals(const AbstractDataType &) const noexcept = undefined;
    virtual bool isConvertible(const AbstractDataType &) const noexcept = undefined;
    virtual void visiteType(AbstractDataTypeVisitor &) const = undefined;
    template<typename T>
    bool instanceOf() const noexcept
    {
        return dynamic_cast<const T *>(this);
    }
    std::size_t hash() const noexcept;
    std::size_t size() const noexcept;

private:
    const std::size_t m_hash;
    const std::size_t m_size;
};

#endif // ABSTRACTDATATYPE_H
