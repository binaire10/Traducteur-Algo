#ifndef ABSTRACTDATATYPE_H
#define ABSTRACTDATATYPE_H

#include <memory>

class ICommonType;
class ICommonTypeVisitor;
class AbstractDataType
{
public:
    AbstractDataType(const std::shared_ptr<ICommonType> &, unsigned pointerLevel = 0u, bool isConst = false, bool isReference = false) noexcept;
    std::string name() const noexcept;
    std::size_t hashType() const noexcept;
    bool equals(const AbstractDataType &) const noexcept;
    bool isConvertible(const AbstractDataType &) const noexcept;
    bool operator ==(const AbstractDataType &) const noexcept;
    bool operator !=(const AbstractDataType &) const noexcept;
    void visite(ICommonTypeVisitor &);
    std::size_t sizeType() const noexcept;
    template<typename>
    inline bool instanceOf();

private:
    std::shared_ptr<ICommonType> d_ptr;
    unsigned m_pointerLevel;
    bool m_isConst;
    bool m_isReference;
};

template<typename T>
inline bool AbstractDataType::instanceOf()
{
    return bool(std::dynamic_pointer_cast<T>(d_ptr));
}

#endif // ABSTRACTDATATYPE_H
