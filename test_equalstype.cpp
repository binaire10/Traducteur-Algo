#include "type/DecimalDataType.h"
#include "type/NumericDataType.h"
#include "type/Character.h"
#include "cassert"

int main()
{
    auto boolean = NumericDataType::getInstance(NumericDataType::NumericType::Boolean);
    auto character = Character::getInstance();
    auto shortInteger = NumericDataType::getInstance(NumericDataType::NumericType::Short);
    auto shortUnsignedInteger = NumericDataType::getInstance(NumericDataType::NumericType::Unsigned_Short);
    auto integer = NumericDataType::getInstance(NumericDataType::NumericType::Int);
    auto unsignedInteger = NumericDataType::getInstance(NumericDataType::NumericType::Unsigned);
    auto longLongInteger = NumericDataType::getInstance(NumericDataType::NumericType::LongLong);
    auto longLongUnsignedInteger = NumericDataType::getInstance(NumericDataType::NumericType::Unsigned_LongLong);
    auto decimal = DecimalDataType::getInstance();
    assert(decimal->equals(*decimal));
    assert(character->equals(*character));
    assert(boolean->equals(*boolean));
    assert(shortInteger->equals(*shortInteger));
    assert(shortUnsignedInteger->equals(*shortUnsignedInteger));
    assert(integer->equals(*integer));
    assert(unsignedInteger->equals(*unsignedInteger));
    assert(longLongInteger->equals(*longLongInteger));
    assert(longLongUnsignedInteger->equals(*longLongUnsignedInteger));

    assert(!decimal->equals(*character));
    assert(!character->equals(*boolean));
    assert(!boolean->equals(*shortInteger));
    assert(!shortInteger->equals(*shortUnsignedInteger));
    assert(!shortUnsignedInteger->equals(*integer));
    assert(!integer->equals(*unsignedInteger));
    assert(!unsignedInteger->equals(*longLongInteger));
    assert(!longLongInteger->equals(*longLongUnsignedInteger));
    assert(!longLongUnsignedInteger->equals(*decimal));

    assert(!decimal->equals(*boolean));
    assert(!character->equals(*shortInteger));
    assert(!boolean->equals(*shortUnsignedInteger));
    assert(!shortInteger->equals(*integer));
    assert(!shortUnsignedInteger->equals(*unsignedInteger));
    assert(!integer->equals(*longLongInteger));
    assert(!unsignedInteger->equals(*longLongUnsignedInteger));
    assert(!longLongInteger->equals(*decimal));
    assert(!longLongUnsignedInteger->equals(*character));

    assert(!decimal->equals(*shortInteger));
    assert(!character->equals(*shortUnsignedInteger));
    assert(!boolean->equals(*integer));
    assert(!shortInteger->equals(*unsignedInteger));
    assert(!shortUnsignedInteger->equals(*longLongInteger));
    assert(!integer->equals(*longLongUnsignedInteger));
    assert(!unsignedInteger->equals(*decimal));
    assert(!longLongInteger->equals(*character));
    assert(!longLongUnsignedInteger->equals(*boolean));

    assert(!decimal->equals(*shortUnsignedInteger));
    assert(!character->equals(*integer));
    assert(!boolean->equals(*unsignedInteger));
    assert(!shortInteger->equals(*longLongInteger));
    assert(!shortUnsignedInteger->equals(*longLongUnsignedInteger));
    assert(!integer->equals(*decimal));
    assert(!unsignedInteger->equals(*character));
    assert(!longLongInteger->equals(*boolean));
    assert(!longLongUnsignedInteger->equals(*shortInteger));

    assert(!decimal->equals(*integer));
    assert(!character->equals(*unsignedInteger));
    assert(!boolean->equals(*longLongInteger));
    assert(!shortInteger->equals(*longLongUnsignedInteger));
    assert(!shortUnsignedInteger->equals(*decimal));
    assert(!integer->equals(*character));
    assert(!unsignedInteger->equals(*boolean));
    assert(!longLongInteger->equals(*shortInteger));
    assert(!longLongUnsignedInteger->equals(*shortUnsignedInteger));

    assert(!decimal->equals(*unsignedInteger));
    assert(!character->equals(*longLongInteger));
    assert(!boolean->equals(*longLongUnsignedInteger));
    assert(!shortInteger->equals(*decimal));
    assert(!shortUnsignedInteger->equals(*character));
    assert(!integer->equals(*boolean));
    assert(!unsignedInteger->equals(*shortInteger));
    assert(!longLongInteger->equals(*shortUnsignedInteger));
    assert(!longLongUnsignedInteger->equals(*integer));

    assert(!decimal->equals(*longLongInteger));
    assert(!character->equals(*longLongUnsignedInteger));
    assert(!boolean->equals(*decimal));
    assert(!shortInteger->equals(*character));
    assert(!shortUnsignedInteger->equals(*boolean));
    assert(!integer->equals(*shortInteger));
    assert(!unsignedInteger->equals(*shortUnsignedInteger));
    assert(!longLongInteger->equals(*integer));
    assert(!longLongUnsignedInteger->equals(*unsignedInteger));

    assert(!decimal->equals(*longLongUnsignedInteger));
    assert(!character->equals(*decimal));
    assert(!boolean->equals(*character));
    assert(!shortInteger->equals(*boolean));
    assert(!shortUnsignedInteger->equals(*boolean));
    assert(!integer->equals(*shortUnsignedInteger));
    assert(!unsignedInteger->equals(*integer));
    assert(!longLongInteger->equals(*unsignedInteger));
    assert(!longLongUnsignedInteger->equals(*longLongInteger));
    return 0;
}
