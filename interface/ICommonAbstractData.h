#ifndef ICOMMONABSTRACTDATA_H
#define ICOMMONABSTRACTDATA_H

#include <string>
#include "IOperator.h"
#include "ICommonAbstractDataVisitable.h"
#include "IArguments.h"

class ICommonAbstractData : public ICommonAbstractDataVisitable
{
public:
    constexpr ICommonAbstractData() noexcept = default;
    virtual std::string name() const noexcept = undefined;
    virtual std::size_t hashType() const noexcept = undefined;
    virtual bool equals(const ICommonAbstractData &) const noexcept = undefined;
    virtual bool convertible(const ICommonAbstractData &) const noexcept = undefined;
    virtual std::size_t size() const noexcept = undefined;
    virtual bool hasOperand(const IOperator &, const IArguments &) const noexcept = undefined;
};

#endif // ICOMMONABSTRACTDATA_H
