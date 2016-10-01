#include "VariadicFunction.h"

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

VariadicFunction::VariadicFunction(const string &Name) : Fonction(Name)
{}

bool VariadicFunction::ArgumenntAllow(unsigned) const
{
    return true;
}

bool VariadicFunction::Validate(const std::list<binaire::SmartPtr<Expression> > &)
{
    return true;
}
