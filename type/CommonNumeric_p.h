#ifndef COMMONNUMERIC_P_H
#define COMMONNUMERIC_P_H

#include "CommonScalar_p.h"

class CommonNumeric;
class CommonNumeric_p : public CommonScalar_p
{
public:
    constexpr CommonNumeric_p(std::size_t s, std::size_t hashType, CommonNumeric::Type c);
    constexpr CommonNumeric::Type type() const;

protected:
    friend class CommonNumeric;
    const CommonNumeric::Type m_type;
};

#include "CommonNumeric_p.inl"

#endif // COMMONNUMERIC_P_H
