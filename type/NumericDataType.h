#ifndef NUMERICDATATYPE_H
#define NUMERICDATATYPE_H

#include "ScalarDataType.h"

class NumericDataType : public ScalarDataType
{
public:
    enum class Type
    {
        Short, Unsigned_Short,
        Int, Unsigned,
        LongLong, Unsigned_LongLong,
        Float, Double
    };
    static std::shared_ptr<DecimalDataType> getInstance(Type) noexcept;
    bool equals(const AbstractDataType &) noexcept override;

protected:
    NumericDataType(Type);
    const Type m_type;
};

#endif // NUMERICDATATYPE_H
