#ifndef IOPERATOR_H
#define IOPERATOR_H

#include "IOperatorVisitable.h"
#include "IOperation.h"

class IOperator : public IOperatorVisitable, public IOperation
{
public:
    constexpr IOperator() noexcept = default;
};

#endif // IOPERATOR_H
