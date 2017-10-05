#include <iostream>
#include "Function.h"
#include <type/CommonScalar.h>
#include <limits>
#include "type/CommonNumeric.h"
#include "type/Character.h"
#include <map>
#include "type/TypeParameters.h"
#include "type/AbstractDataType.h"
#include "expression/Expression.h"
#include "expression/ValueExpression.h"
#include "operation/Sum.h"

using namespace std;

int main()
{
//    system("chcp 65001");
    TypeParameters arg({AbstractDataType(CommonNumeric::getInstance(CommonNumeric::Type::Short)),
                      AbstractDataType(CommonNumeric::getInstance(CommonNumeric::Type::Short))});

    ArgumentExpression arg2({ std::make_shared<ValueExpression<long long>>(5),
                        std::make_shared<ValueExpression<double>>(5)});
    Expression exp(Sum::getInstance(), std::make_shared<ArgumentExpression>(arg2));

//    ValueExpression<std::string> val5("test");

    cout << boolalpha;
    cout << "Hello wordl !" << endl;

    cout << arg.equals(arg2) << endl;
    cout << arg.isConvertible(arg2) << endl;

    AbstractDataType test(CommonNumeric::getInstance(CommonNumeric::Type::Short));
    cout << test.instanceOf<CommonScalar>() << endl;
    cout << test.instanceOf<CommonNumeric>() << endl;
    cout << test.instanceOf<Character>() << endl;
    cout << exp.result().name() << endl;

    return 0;
}
