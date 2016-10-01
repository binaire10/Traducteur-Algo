#include "ExpressionToInstruction.h"
#include "struccore.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

ExpressionToInstruction::ExpressionToInstruction(const binaire::SmartPtr<Expression> &a) : Exp(a)
{}

void ExpressionToInstruction::ToCppCode(ostream &Result)
{
    Result  << string(Indentation*4, ' ');
    Exp->ToCppCode(Result);
    Result << ";\n";
}
