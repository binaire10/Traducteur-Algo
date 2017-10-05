#ifndef ARGUMENTTYPE_H
#define ARGUMENTTYPE_H

#include <vector>
#include "../interface/IParameters.h"
#include "AbstractDataType.h"

class TypeParameters : public IParameters
{
public:
    TypeParameters();
    TypeParameters(const std::vector<AbstractDataType> &);
    TypeParameters(const std::initializer_list<AbstractDataType> &);
    void visiteArgument(IParametersVisitor &) const override;
    std::size_t size() const noexcept override;
    AbstractDataType at(std::size_t) const override;

private:
    std::vector<AbstractDataType> m_types;
};

#endif // ARGUMENTTYPE_H
