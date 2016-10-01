#pragma once
#include <MyMemory/SmartPtr.hpp>
#include <list>
#include "Expression.h"
#include "Fonction.h"


namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        class FonctionCall : public Expression
        {
        public:
            FonctionCall(Fonction *x, const std::list< binaire::SmartPtr<Expression> > &arg);
            FonctionCall(const FonctionCall &) = delete;
            FonctionCall &operator=(const FonctionCall &) = delete;
            void ToCppCode(std::ostream &) override;
            bool isFinalValue() override;

        private:
            Fonction *fonction;
            std::list< binaire::SmartPtr<Expression> > arg;
        };
    }
}
