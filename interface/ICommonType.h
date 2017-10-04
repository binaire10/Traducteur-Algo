#ifndef ICOMMONTYPE_H
#define ICOMMONTYPE_H

#include <string>
#include "ICommonTypeVisitable.h"

class ICommonType : public ICommonTypeVisitable
{
public:
    constexpr ICommonType() noexcept = default;
    virtual std::string name() const noexcept = undefined;
    virtual std::size_t hashType() const noexcept = undefined;
    virtual bool equals(const ICommonType &) const noexcept = undefined;
    virtual bool convertible(const ICommonType &) const noexcept = undefined;
    virtual std::size_t size() const noexcept = undefined;
};

#endif // ICOMMONTYPE_H
