#ifndef IARGUMENTS_H
#define IARGUMENTS_H

#include "IArgumentVisitable.h"
#include "../type/Type.h"

class IArguments : public IArgumentVisitable
{
public:
    constexpr IArguments() noexcept = default;
    bool isConvertible(const IArguments &) const noexcept;
    bool equals(const IArguments &) const noexcept;
    virtual std::size_t size() const noexcept = undefined;
    virtual Type at(std::size_t) const = undefined;
};

#endif // IARGUMENTS_H
