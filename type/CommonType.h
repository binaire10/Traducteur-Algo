#ifndef COMMONTYPE_H
#define COMMONTYPE_H

#include <memory>
#include <vector>
#include "../interface/ICommonType.h"
#include "../interface/IArguments.h"

class CommonType : public ICommonType
{
public:
    CommonType(const std::vector<std::pair<std::shared_ptr<ICommonType>, std::shared_ptr<IArguments>>> &array);
    bool hasOperand(const IOperator &, const IArguments &) const noexcept override;

private:
    std::vector<std::pair<std::shared_ptr<ICommonType>, std::shared_ptr<IArguments>>> m_operand;
};

#endif // COMMONTYPE_H
