#ifndef SIZEOFARRAY_H
#define SIZEOFARRAY_H

#include "../interface/IOperator.h"

class SizeOfArray : public IOperator
{
public:
    SizeOfArray();
    std::string operatorName() override;
    Type resultOperation(const IArguments &) override;
    void visiteOperation(IOperationVisitor &) const override;
    void visiteOperator(IOperatorVisitor &) const override;
};

#endif // SIZEOFARRAY_H
