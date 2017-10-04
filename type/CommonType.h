#ifndef COMMONTYPE_H
#define COMMONTYPE_H

#include <memory>
#include <list>
#include "../interface/ICommonType.h"
#include "../interface/IArguments.h"

class CommonType : public ICommonType
{
public:
    CommonType(const std::list<std::pair<std::shared_ptr<IOperator>, std::shared_ptr<IArguments>>> &array = {});
    bool hasOperand(const IOperator &, const IArguments &) const noexcept override;

protected:
    void addParamter(const std::pair<std::shared_ptr<IOperator>, std::shared_ptr<IArguments>> &);
    void addParamter(const std::list<std::pair<std::shared_ptr<IOperator>, std::shared_ptr<IArguments>>> &);

private:
    std::list<std::pair<std::shared_ptr<IOperator>, std::shared_ptr<IArguments>>> m_operand;
};

#endif // COMMONTYPE_H
