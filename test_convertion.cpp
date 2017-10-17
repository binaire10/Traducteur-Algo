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
    assert(decimal->isConvertible(*decimal));
    assert(character->isConvertible(*character));
    assert(boolean->isConvertible(*boolean));
    assert(shortInteger->isConvertible(*shortInteger));
    assert(shortUnsignedInteger->isConvertible(*shortUnsignedInteger));
    assert(integer->isConvertible(*integer));
    assert(unsignedInteger->isConvertible(*unsignedInteger));
    assert(longLongInteger->isConvertible(*longLongInteger));
    assert(longLongUnsignedInteger->isConvertible(*longLongUnsignedInteger));
    return 0;
}
