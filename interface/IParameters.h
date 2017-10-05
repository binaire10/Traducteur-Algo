#ifndef IPARAMETERS_H
#define IPARAMETERS_H

#include "IParametersVisitable.h"
#include "../type/AbstractDataType.h"

class IParameters : public IParametersVisitable
{
public:
    constexpr IParameters() noexcept = default;
    bool isConvertible(const IParameters &) const noexcept;
    bool equals(const IParameters &) const noexcept;
    virtual std::size_t size() const noexcept = undefined;
    virtual AbstractDataType at(std::size_t) const = undefined;
};

#endif // IPARAMETERS_H
