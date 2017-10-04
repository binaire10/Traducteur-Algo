#include <iostream>
#include "Function.h"
#include <type/CommonScalar.h>
#include <limits>
#include "type/Numeric.h"
#include "type/Character.h"
#include <map>
#include "type/ArgumentType.h"
#include "type/Type.h"
#include "expression/Expression.h"
#include "expression/ValueExpression.h"
#include "operation/Sum.h"

using namespace std;

int main()
{
//    system("chcp 65001");
    ArgumentType arg({Type(Numeric::getInstance(Numeric::Type::Short)),
                      Type(Numeric::getInstance(Numeric::Type::Short))});

    ArgumentExpression arg2({ std::make_shared<ValueExpression<long long>>(5),
                        std::make_shared<ValueExpression<double>>(5)});
    Expression exp(Sum::getInstance(), std::make_shared<ArgumentExpression>(arg2));

//    ValueExpression<std::string> val5("test");

    cout << boolalpha;
    cout << "Hello wordl !" << endl;

    cout << arg.equals(arg2) << endl;
    cout << arg.isConvertible(arg2) << endl;

    Type test(Numeric::getInstance(Numeric::Type::Short));
    cout << test.instanceOf<CommonScalar>() << endl;
    cout << test.instanceOf<Numeric>() << endl;
    cout << test.instanceOf<Character>() << endl;
    cout << exp.result().name() << endl;

    return 0;
}
