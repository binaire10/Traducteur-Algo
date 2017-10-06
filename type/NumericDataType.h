#ifndef NUMERICDATATYPE_H
#define NUMERICDATATYPE_H

#include <memory>
#include "ScalarDataType.h"

class NumericDataType : public ScalarDataType
{
public:
    enum class Type
    {
        Boolean,
        Short, Unsigned_Short,
        Int, Unsigned,
        LongLong, Unsigned_LongLong,
        Float, Double
    };

    static constexpr std::size_t sizeofType(Type t)
    {
        switch (t) {
        case Type::Short:
        case Type::Unsigned_Short:
            return 2ull;
            break;
        case Type::Int:
        case Type::Unsigned:
        case Type::Float:
            return 4ull;
            break;
        case Type::LongLong:
        case Type::Unsigned_LongLong:
        case Type::Double:
            return 8ull;
            break;
        default:
            return 0ull;
            break;
        }
    }

    static std::shared_ptr<NumericDataType> getInstance(Type) noexcept;
    bool equals(const AbstractDataType &) const noexcept override;
    void visiteType(AbstractDataTypeVisitor &) const override;

protected:
    NumericDataType(Type);
    const Type m_type;
};

#endif // NUMERICDATATYPE_H
