#ifndef COMMONNUMERIC_P_INL
#define COMMONNUMERIC_P_INL

#include "CommonNumeric.h"
#include "CommonNumeric_p.h"

constexpr CommonNumeric_p::CommonNumeric_p(std::size_t s, std::size_t hashType, CommonNumeric::Type c) : CommonScalar_p(s, hashType), m_type(c)
{}

constexpr CommonNumeric::Type CommonNumeric_p::type() const
{
    return m_type;
}

#endif // COMMONNUMERIC_P_INL
