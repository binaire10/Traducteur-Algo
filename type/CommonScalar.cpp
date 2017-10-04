#include "CommonScalar.h"
#include "CommonScalar_p.h"
#include <cmath>

CommonScalar::CommonScalar(std::size_t octet, std::size_t hash) : d_ptr(std::make_shared<CommonScalar_p>(octet, hash ^ (computeHash(octet)<<1)))
{}

CommonScalar::CommonScalar(const std::shared_ptr<CommonScalar_p> &ptr) noexcept : d_ptr(ptr)
{}

bool CommonScalar::convertible(const ICommonAbstractData &v) const noexcept
{
    return this == &v || dynamic_cast<const CommonScalar *>(&v);
}


std::size_t CommonScalar::hashType() const noexcept
{
    return getData()->hashType();
}

std::size_t CommonScalar::computeHash(std::size_t octet) noexcept
{
    return std::hash<std::size_t>()(octet);
}

std::size_t CommonScalar::size() const noexcept
{
    return getData()->size();
}
