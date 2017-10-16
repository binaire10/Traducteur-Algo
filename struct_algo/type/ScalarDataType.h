#ifndef SCALARDATATYPE_H
#define SCALARDATATYPE_H

#include "AbstractDataType.h"

class ScalarDataType : public AbstractDataType
{
public:
    bool isConvertible(const AbstractDataType &) const noexcept override;

protected:
    ScalarDataType(std::size_t hash, std::size_t size) noexcept;
};

#endif // SCALARDATATYPE_H
