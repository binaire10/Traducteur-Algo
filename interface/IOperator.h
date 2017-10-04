#ifndef IOPERATOR_H
#define IOPERATOR_H

#include "IOperatorVisitable.h"

class IOperator : public IOperatorVisitable
{
public:
    constexpr IOperator() noexcept = default;
};

#endif // IOPERATOR_H
