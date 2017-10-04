#ifndef IFUNCTION_H
#define IFUNCTION_H

#include "IFunctionVisitable.h"
#include "IOperation.h"

class IFunction : public IFunctionVisitable, public IOperation
{
public:
    constexpr IFunction() = default;
};

#endif // IFUNCTION_H
