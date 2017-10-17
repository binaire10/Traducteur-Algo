#ifndef ABSTRACTDATATYPE_H
#define ABSTRACTDATATYPE_H

#include <utility>
#include "../interface/AbstractDataTypeVisitor.h"

class AbstractDataType
{
public:
    constexpr AbstractDataType() noexcept
    {}
    virtual bool equals(const AbstractDataType &) const noexcept = undefined;
    virtual bool isConvertible(const AbstractDataType &) const noexcept = undefined;
    virtual void visiteType(AbstractDataTypeVisitor &) const = undefined;
    template<typename T>
    bool instanceOf() const noexcept
    {
        return dynamic_cast<const T *>(this);
    }
};

#endif // ABSTRACTDATATYPE_H
