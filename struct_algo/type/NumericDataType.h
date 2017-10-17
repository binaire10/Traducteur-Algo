#ifndef NUMERICDATATYPE_H
#define NUMERICDATATYPE_H

#include <memory>
#include "ScalarDataType.h"

class NumericDataType : public ScalarDataType
{
public:
    enum class NumericType
    {
        Boolean,
        Short, Unsigned_Short,
        Int, Unsigned,
        LongLong, Unsigned_LongLong
    };

    static constexpr ScalarDataType::Type toScalarType(NumericType t) noexcept
    {
        switch (t) {
        case NumericDataType::NumericType::Boolean:
            return ScalarDataType::Type::Boolean;
            break;
        case NumericDataType::NumericType::Unsigned_Short:
            return ScalarDataType::Type::Unsigned_Short;
            break;
        case NumericDataType::NumericType::Short:
            return ScalarDataType::Type::Short;
            break;
        case NumericDataType::NumericType::Int:
            return ScalarDataType::Type::Int;
            break;
        case NumericDataType::NumericType::Unsigned:
            return ScalarDataType::Type::Unsigned;
            break;
        case NumericDataType::NumericType::LongLong:
            return ScalarDataType::Type::LongLong;
            break;
        case NumericDataType::NumericType::Unsigned_LongLong:
            return ScalarDataType::Type::Unsigned_LongLong;
            break;
        default:
            break;
        }
    }

    static std::shared_ptr<NumericDataType> getInstance(NumericType) noexcept;
    bool equals(const AbstractDataType &) const noexcept override;
    void visiteType(AbstractDataTypeVisitor &) const override;
    NumericDataType::NumericType getType() const;

protected:
    NumericDataType(NumericType);
    const NumericType m_type;
};

#endif // NUMERICDATATYPE_H
