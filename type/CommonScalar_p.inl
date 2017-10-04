#ifndef COMMONSCALAR_P_INL
#define COMMONSCALAR_P_INL

#include "CommonScalar_p.h"

constexpr CommonScalar_p::CommonScalar_p(std::size_t size, std::size_t hash) : m_size(size), m_hashType(hash)
{}

constexpr std::size_t CommonScalar_p::size() const
{
    return m_size;
}

constexpr std::size_t CommonScalar_p::hashType() const
{
    return m_hashType;
}

#endif // COMMONSCALAR_P_INL
