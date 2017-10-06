#ifndef ABSTRACTDATATYPE_H
#define ABSTRACTDATATYPE_H

#include <utility>
#include "../interface/IAbstractDataTypeVisitor.h"
#include "../interface/IOperator.h"
#include "../interface/AbstractOperator.h"

class AbstractDataType
{
public:
    constexpr AbstractDataType() noexcept = default;
    virtual bool equals(const AbstractDataType &) noexcept = undefined;
    virtual bool isConvertible(const AbstractDataType &) noexcept = undefined;
    virtual void visiteType(IAbstractDataTypeVisitor &) const = undefined;
};

#endif // ABSTRACTDATATYPE_H
