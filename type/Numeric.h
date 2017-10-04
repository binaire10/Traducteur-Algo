#ifndef NUMERIC_H
#define NUMERIC_H

#include "CommonScalar.h"

class Numeric_p;
class Numeric : public CommonScalar
{
public:
    enum class Type
    {
        Short, Unsigned_Short,
        Int, Unsigned,
        LongLong, Unsigned_LongLong,
        Float, Double
    };
    static constexpr std::size_t sizeofType(Numeric::Type t)
    {
        switch (t) {
        case Numeric::Type::Short:
        case Numeric::Type::Unsigned_Short:
            return 2ull;
            break;
        case Numeric::Type::Int:
        case Numeric::Type::Unsigned:
        case Numeric::Type::Float:
            return 4ull;
            break;
        case Numeric::Type::LongLong:
        case Numeric::Type::Unsigned_LongLong:
        case Numeric::Type::Double:
            return 8ull;
            break;
        default:
            return 0ull;
            break;
        }
    }

    static std::shared_ptr<Numeric> getInstance(Type t);

    void visiteCommonType(ICommonAbstractDataVisitor &) const override;
    bool equals(const ICommonAbstractData &) const noexcept override;
    Type type() const;

protected:
    Numeric(Numeric::Type type);
    Numeric(const std::shared_ptr<Numeric_p> &);
    inline const Numeric_p *getData() const;

    // ICommonType interface
public:
    std::string name() const noexcept override;
};

inline const Numeric_p *Numeric::getData() const
{
    return reinterpret_cast<const Numeric_p *>(d_ptr.get());
}


#endif // NUMERIC_H
