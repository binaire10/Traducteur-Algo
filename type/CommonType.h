#ifndef COMMONTYPE_H
#define COMMONTYPE_H

#include <memory>
#include <list>
#include "../interface/ICommonType.h"
#include "../interface/IArguments.h"

class CommonType : public ICommonType
{
public:
    CommonType(const std::list<std::shared_ptr<IOperator>> &array = {});
    bool hasOperand(const IOperator &, const IArguments &) const noexcept override;

protected:
    void addParamter(const std::shared_ptr<IOperator> &);
    void addParamter(const std::list<std::shared_ptr<IOperator>> &);

private:
    std::list<std::shared_ptr<IOperator>> m_operand;
};

#endif // COMMONTYPE_H
