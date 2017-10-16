#ifndef EXPRESSIONABLE_H
#define EXPRESSIONABLE_H

#include <memory>
#include "IExpressionVisitable.h"

class AbstractDataType;
class Expressionable : public IExpressionVisitable
{
public:
    // https://stackoverflow.com/questions/3601602/what-are-rvalues-lvalues-xvalues-glvalues-and-prvalues
    enum value_cast
    {
        nvalue = 0x00, // none value
        value = 0x01, // value
        lvalue = 0x02 | value, // left value (http://en.cppreference.com/w/cpp/language/value_category#lvalue)
        xvalue = 0x04 | value, // eXpirate object (http://en.cppreference.com/w/cpp/language/value_category#xvalue)
        prvalue = 0x08 | value, // pure right value (http://en.cppreference.com/w/cpp/language/value_category#prvalue)
        rvalue = prvalue | xvalue, // right value (http://en.cppreference.com/w/cpp/language/value_category#rvalue)
        glvalue = lvalue | xvalue, // generalized left value (http://en.cppreference.com/w/cpp/language/value_category#glvalue)
    };
    constexpr Expressionable() noexcept = default;
    virtual std::shared_ptr<AbstractDataType> result() const = undefined;
    virtual value_cast resultValueCast() const noexcept = undefined;
};

#include "../type/AbstractDataType.h"

#endif // EXPRESSIONABLE_H
