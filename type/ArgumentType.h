#ifndef ARGUMENTTYPE_H
#define ARGUMENTTYPE_H

#include <vector>
#include "../interface/IArguments.h"
#include "Type.h"

class ArgumentType : public IArguments
{
public:
    ArgumentType();
    ArgumentType(const std::vector<Type> &);
    ArgumentType(const std::initializer_list<Type> &);
    void visiteArgument(IArgumentVisitor &) const override;
    std::size_t size() const noexcept override;
    Type at(std::size_t) const override;

private:
    std::vector<Type> m_types;
};

#endif // ARGUMENTTYPE_H