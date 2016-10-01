#include "FonctionCall.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;
using namespace MathExpression;

FonctionCall::FonctionCall(Fonction *x, const std::list<binaire::SmartPtr<Expression> > &arg) : Expression(x->GetOutput()), fonction(x), arg(arg)
{
    if(!x->Validate(arg))
        throw std::runtime_error("Bad Type");
}

void FonctionCall::ToCppCode(ostream &os)
{
    os << fonction->GetName() << '(';
    std::list< binaire::SmartPtr<Expression> >::iterator begin(arg.begin());

    if(begin != arg.end())
    {
        (*begin)->ToCppCode(os);
        ++begin;
    }

    while(begin != arg.end())
    {
        os << ", ";
        (*begin)->ToCppCode(os);
        ++begin;
    }
    os << ')';
}

bool FonctionCall::isFinalValue()
{
    return false;
}
