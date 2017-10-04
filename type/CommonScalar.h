#ifndef COMMONSCALAR_H
#define COMMONSCALAR_H

#include <memory>
#include "CommonType.h"
#include "../interface/ICommonType.h"

class CommonScalar_p;
class CommonScalar : public CommonType
{
protected:
    inline const CommonScalar_p *getData() const;
    CommonScalar(std::size_t octet, std::size_t hash);
    CommonScalar(const std::shared_ptr<CommonScalar_p> &) noexcept;

public:
    bool convertible(const ICommonType &v) const noexcept override;
    std::size_t hashType() const noexcept final;
    static std::size_t computeHash(std::size_t octet) noexcept;
    std::size_t size() const noexcept override;

protected:
    std::shared_ptr<CommonScalar_p> d_ptr;
};

inline const CommonScalar_p *CommonScalar::getData() const
{
    return reinterpret_cast<const CommonScalar_p *>(d_ptr.get());
}

#include "CommonScalar_p.h"

#endif // COMMONSCALAR_H
