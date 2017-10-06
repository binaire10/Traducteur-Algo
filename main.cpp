#include <iostream>
#include "Function.h"
#include <limits>
#include <iomanip>
#include <map>
#include "type/AbstractDataType.h"
#include "operation/Sum.h"
#include <vector>
#include "type/NumericDataType.h"
#include "expression/Expression.h"
#include "expression/ValueExpression.h"

using namespace std;

int main()
{/*
//    system("chcp 65001");
    TypeParameters arg({AbstractDataType(CommonNumeric::getInstance(CommonNumeric::Type::Short)),
                      AbstractDataType(CommonNumeric::getInstance(CommonNumeric::Type::Short))});
*/
    ArgumentExpression arg2({ std::make_shared<ValueExpression<long long>>(5),
                        std::make_shared<ValueExpression<double>>(5)});
    Expression exp(Sum::getInstance(), std::make_shared<ArgumentExpression>(arg2));

//    ValueExpression<std::string> val5("test");

    cout << boolalpha;
    cout << "Hello wordl !" << endl;
/*
    cout << arg.equals(arg2) << endl;
    cout << arg.isConvertible(arg2) << endl;
*/
    std::shared_ptr<AbstractDataType> test(NumericDataType::getInstance(NumericDataType::Type::Short));
    cout << test->instanceOf<ScalarDataType>() << endl;
    cout << test->instanceOf<NumericDataType>() << endl;
    cout << test->instanceOf<Character>() << endl;
    cout << "0x" << hex << setfill('0') << setw(sizeof(std::size_t)*2)<< exp.result()->hash() << endl;
    cout << "Hello world!" << endl;

    return 0;
}
