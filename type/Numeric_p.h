#ifndef NUMERIC_P_H
#define NUMERIC_P_H

#include "CommonScalar_p.h"

class Numeric;
class Numeric_p : public CommonScalar_p
{
public:
    constexpr Numeric_p(std::size_t s, std::size_t hashType, Numeric::Type c);
    constexpr Numeric::Type type() const;

protected:
    friend class Numeric;
    const Numeric::Type m_type;
};

#include "Numeric_p.inl"

#endif // NUMERIC_P_H
