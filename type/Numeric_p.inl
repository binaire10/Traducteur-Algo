#ifndef NUMERIC_P_INL
#define NUMERIC_P_INL

#include "Numeric.h"
#include "numeric_p.h"

constexpr Numeric_p::Numeric_p(std::size_t s, std::size_t hashType, Numeric::Type c) : CommonScalar_p(s, hashType), m_type(c)
{}

constexpr Numeric::Type Numeric_p::type() const
{
    return m_type;
}

#endif // NUMERIC_P_INL
