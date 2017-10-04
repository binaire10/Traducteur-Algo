#ifndef ARGUMENTTYPE_H
#define ARGUMENTTYPE_H

#include <vector>
#include "../interface/IArguments.h"
#include "AbstractDataType.h"

class ArgumentType : public IArguments
{
public:
    ArgumentType();
    ArgumentType(const std::vector<AbstractDataType> &);
    ArgumentType(const std::initializer_list<AbstractDataType> &);
    void visiteArgument(IArgumentVisitor &) const override;
    std::size_t size() const noexcept override;
    AbstractDataType at(std::size_t) const override;

private:
    std::vector<AbstractDataType> m_types;
};

#endif // ARGUMENTTYPE_H
