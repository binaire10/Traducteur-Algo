#include "ScalarDataType.h"

constexpr bool isConvertible(ScalarDataType::Type from, ScalarDataType::Type to)
{
    switch (from) {
    case ScalarDataType::Type::Boolean:
        return true;
        break;
    case ScalarDataType::Type::Double:
        switch (to) {
        case ScalarDataType::Type::Double:
            return true;
            break;
        default:
            return false;
            break;
        }
    case ScalarDataType::Type::Float:
        switch (to) {
        case ScalarDataType::Type::Double:
        case ScalarDataType::Type::Float:
            return true;
            break;
        default:
            return false;
            break;
        }
    case ScalarDataType::Type::Int:
        switch (to) {
        case ScalarDataType::Type::Double:
        case ScalarDataType::Type::Float:
        case ScalarDataType::Type::Int:
        case ScalarDataType::Type::LongLong:
            return true;
            break;
        default:
            return false;
            break;
        }
    case ScalarDataType::Type::LongLong:
        switch (to) {
        case ScalarDataType::Type::Double:
        case ScalarDataType::Type::LongLong:
            return true;
            break;
        default:
            return false;
            break;
        }
    case ScalarDataType::Type::Short:
        switch (to) {
        case ScalarDataType::Type::Short:
        case ScalarDataType::Type::Double:
        case ScalarDataType::Type::Float:
        case ScalarDataType::Type::Int:
        case ScalarDataType::Type::LongLong:
            return true;
            break;
        default:
            return false;
            break;
        }
    case ScalarDataType::Type::Unsigned:
        switch (to) {
        case ScalarDataType::Type::Unsigned:
        case ScalarDataType::Type::Unsigned_LongLong:
        case ScalarDataType::Type::LongLong:
        case ScalarDataType::Type::Double:
            return true;
            break;
        default:
            return false;
            break;
        }
    case ScalarDataType::Type::Unsigned_Short:
        switch (to) {
        case ScalarDataType::Type::Unsigned_Short:
        case ScalarDataType::Type::Unsigned:
        case ScalarDataType::Type::Unsigned_LongLong:
        case ScalarDataType::Type::LongLong:
        case ScalarDataType::Type::Float:
        case ScalarDataType::Type::Double:
            return true;
            break;
        default:
            return false;
            break;
        }
    case ScalarDataType::Type::Unsigned_LongLong:
        switch (to) {
        case ScalarDataType::Type::Unsigned_LongLong:
        case ScalarDataType::Type::Double:
            return true;
            break;
        default:
            return false;
            break;
        }
    case ScalarDataType::Type::Char:
        switch (to) {
        case ScalarDataType::Type::LongLong:
        case ScalarDataType::Type::Int:
        case ScalarDataType::Type::Short:
        case ScalarDataType::Type::Float:
        case ScalarDataType::Type::Double:
        case ScalarDataType::Type::Char:
            return true;
            break;
        default:
            return false;
            break;
        }
    default:
        break;
    }
}

bool ScalarDataType::isConvertible(const AbstractDataType &data) const noexcept
{
    const ScalarDataType *ptr = dynamic_cast<const ScalarDataType *>(&data);
    return ptr && ::isConvertible(m_type, ptr->m_type);
}

ScalarDataType::ScalarDataType(Type type) noexcept : AbstractDataType(), m_type(type)
{}
