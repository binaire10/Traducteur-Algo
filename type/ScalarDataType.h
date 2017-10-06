#ifndef SCALARDATATYPE_H
#define SCALARDATATYPE_H

#include "AbstractDataType.h"

class ScalarDataType : public AbstractDataType
{
public:
    constexpr ScalarDataType() noexcept = default;
    bool isConvertible(const AbstractDataType &) noexcept override;
};

#endif // SCALARDATATYPE_H
