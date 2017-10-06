#include "ScalarDataType.h"

bool ScalarDataType::isConvertible(const AbstractDataType &data) const noexcept
{
    return dynamic_cast<const ScalarDataType *>(&data);
}

ScalarDataType::ScalarDataType(std::size_t hash, std::size_t size) noexcept : AbstractDataType(hash, size)
{}
