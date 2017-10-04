#ifndef TYPE_H
#define TYPE_H

#include <memory>

class ICommonType;
class ICommonTypeVisitor;
class Type
{
public:
    Type(const std::shared_ptr<ICommonType> &, unsigned pointerLevel = 0u, bool isConst = false, bool isReference = false) noexcept;
    std::string name() const noexcept;
    std::size_t hashType() const noexcept;
    bool equals(const Type &) const noexcept;
    bool isConvertible(const Type &) const noexcept;
    bool operator ==(const Type &) const noexcept;
    bool operator !=(const Type &) const noexcept;
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
inline bool Type::instanceOf()
{
    return bool(std::dynamic_pointer_cast<T>(d_ptr));
}

#endif // TYPE_H
