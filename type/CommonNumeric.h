#ifndef COMMONNUMERIC_H
#define COMMONNUMERIC_H

#include "CommonScalar.h"

class CommonNumeric_p;
class CommonNumeric : public CommonScalar
{
public:
    enum class Type
    {
        Short, Unsigned_Short,
        Int, Unsigned,
        LongLong, Unsigned_LongLong,
        Float, Double
    };
    static constexpr std::size_t sizeofType(CommonNumeric::Type t)
    {
        switch (t) {
        case CommonNumeric::Type::Short:
        case CommonNumeric::Type::Unsigned_Short:
            return 2ull;
            break;
        case CommonNumeric::Type::Int:
        case CommonNumeric::Type::Unsigned:
        case CommonNumeric::Type::Float:
            return 4ull;
            break;
        case CommonNumeric::Type::LongLong:
        case CommonNumeric::Type::Unsigned_LongLong:
        case CommonNumeric::Type::Double:
            return 8ull;
            break;
        default:
            return 0ull;
            break;
        }
    }

    static std::shared_ptr<CommonNumeric> getInstance(Type t);

    void visiteCommonType(ICommonAbstractDataVisitor &) const override;
    bool equals(const ICommonAbstractData &) const noexcept override;
    Type type() const;

protected:
    CommonNumeric(CommonNumeric::Type type);
    CommonNumeric(const std::shared_ptr<CommonNumeric_p> &);
    inline const CommonNumeric_p *getData() const;

    // ICommonType interface
public:
    std::string name() const noexcept override;
};

inline const CommonNumeric_p *CommonNumeric::getData() const
{
    return reinterpret_cast<const CommonNumeric_p *>(d_ptr.get());
}


#endif // COMMONNUMERIC_H
