#include "ScalarDataType.h"

bool ScalarDataType::isConvertible(const AbstractDataType &data) noexcept
{
    return dynamic_cast<const ScalarDataType *>(&data);
}
