#ifndef IFUNCTION_H
#define IFUNCTION_H

#include "IFunctionVisitable.h"
#include "AbstractOperation.h"

class IFunction : public IFunctionVisitable, public AbstractOperation
{
public:
    constexpr IFunction() = default;
};

#endif // IFUNCTION_H
