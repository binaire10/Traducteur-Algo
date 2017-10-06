#ifndef IPARAMETERS_H
#define IPARAMETERS_H

#include <memory>
#include "IParametersVisitable.h"

class AbstractDataType;
class IParameters : public IParametersVisitable
{
public:
    constexpr IParameters() noexcept = default;
    bool isConvertible(const IParameters &) const noexcept;
    bool equals(const IParameters &) const noexcept;
    virtual std::size_t size() const noexcept = undefined;
    virtual std::shared_ptr<AbstractDataType> at(std::size_t) const = undefined;
};

#include "../type/AbstractDataType.h"

#endif // IPARAMETERS_H
