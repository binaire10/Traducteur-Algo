#include "SizeOfArray.h"
#include "../interface/IOperationVisitor.h"
#include "../interface/IOperatorVisitor.h"
#include "../type/Numeric.h"

SizeOfArray::SizeOfArray()
{}

std::string SizeOfArray::operatorName()
{
    return "SizeOfArray";
}

Type SizeOfArray::resultOperation(const IArguments &arg)
{
    if(arg.size() != 1u)
        throw std::runtime_error("operation SizeOfArray must have one argument");
    if(arg.at(0).pointerLevel())
        return Type(Numeric::getInstance(Numeric::Type::Unsigned));
    throw std::runtime_error("operation SizeOfArray must be an array");
}

void SizeOfArray::visiteOperation(IOperationVisitor &v) const
{
    v.visiteOperation(*this);
}

void SizeOfArray::visiteOperator(IOperatorVisitor &v) const
{
    v.visiteOperator(*this);
}
