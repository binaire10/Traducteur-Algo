#ifndef COMMONSCALAR_H
#define COMMONSCALAR_H

#include <memory>
#include "CommonAbstractData.h"
#include "../interface/ICommonAbstractData.h"

class CommonScalar_p;
class CommonScalar : public CommonAbstractData
{
protected:
    inline const CommonScalar_p *getData() const;
    CommonScalar(std::size_t octet, std::size_t hash);
    CommonScalar(const std::shared_ptr<CommonScalar_p> &) noexcept;

public:
    bool convertible(const ICommonAbstractData &v) const noexcept override;
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

#endif // COMMONSCALAR_H
