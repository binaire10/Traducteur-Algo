#pragma once
#include <string>
#include <list>
#include <MyMemory/SmartPtr.hpp>
#include "Expression.h"
#include "Fonction.h"

namespace ElementAlgorithmique
{
    class VariadicFunction : public Fonction
    {
    public:
        VariadicFunction() = default;
        VariadicFunction(const std::string &Name);
        bool ArgumenntAllow(unsigned) const override;
        bool Validate(const std::list<binaire::SmartPtr<Expression> > &inp) override;
    };
}
