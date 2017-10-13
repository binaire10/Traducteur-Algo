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
#include "type/ParametersUtility.h"
#include "type/ConstAbstractDataType.h"
#include "type/AbstractDataTypeReference.h"
#include "exception/BadModificator.h"

using namespace std;

int main()
{
//    system("chcp 65001");
    std::list<std::shared_ptr<AbstractDataType>> arg({NumericDataType::getInstance(NumericDataType::Type::Short),
                      NumericDataType::getInstance(NumericDataType::Type::Short)});

    Expression exp(Sum::getInstance(), { std::make_shared<ValueExpression<long long>>(5),
                                         std::make_shared<ValueExpression<double>>(5)});

//    ValueExpression<std::string> val5("test");

    cout << boolalpha;
    cout << "Hello wordl !" << endl;

    cout << isEquals(arg, exp.arguments()) << endl;
    cout << isConvertibles(arg, exp.arguments()) << endl;

    std::shared_ptr<AbstractDataType> test(NumericDataType::getInstance(NumericDataType::Type::Short));
    cout << test->instanceOf<ScalarDataType>() << endl;
    cout << test->instanceOf<NumericDataType>() << endl;
    cout << test->instanceOf<Character>() << endl;
    cout << "0x" << hex << setfill('0') << setw(sizeof(std::size_t)*2)<< exp.result()->hash() << endl;
    cout << "Hello world!" << endl;

    try {
        std::make_shared<AbstractDataTypeReference>(std::make_shared<ConstAbstractDataType>(NumericDataType::getInstance(NumericDataType::Type::Short)));
    }
    catch(const BadModificator &e)
    {
        cerr << "BadModificator " << e.what() << endl;
    }

    return 0;
}
