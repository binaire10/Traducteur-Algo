#ifndef COMMONSCALAR_P_H
#define COMMONSCALAR_P_H

#include <utility>

class CommonScalar;
class CommonScalar_p
{
public:
    constexpr CommonScalar_p(std::size_t size, std::size_t hash);
    constexpr std::size_t size() const;
    constexpr std::size_t hashType() const;

private:
    friend class CommonScalar;
    const std::size_t m_size;
    const std::size_t m_hashType;
};

#include "CommonScalar_p.inl"

#endif // COMMONSCALAR_P_H
