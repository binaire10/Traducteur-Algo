#include "AbstractDataType.h"

std::size_t AbstractDataType::hash() const noexcept
{
    return m_hash;
}

std::size_t AbstractDataType::size() const noexcept
{
    return m_size;
}
