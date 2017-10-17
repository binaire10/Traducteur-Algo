#ifndef SCALARDATATYPE_H
#define SCALARDATATYPE_H

#include "AbstractDataType.h"

class ScalarDataType : public AbstractDataType
{
public:
    enum class Type
    {
        Boolean, Char,
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

    bool isConvertible(const AbstractDataType &) const noexcept override;

protected:
    ScalarDataType(Type type) noexcept;

private:
    Type m_type;
};

#endif // SCALARDATATYPE_H
