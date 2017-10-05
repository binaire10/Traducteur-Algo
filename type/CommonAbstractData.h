#ifndef COMMONABSTRACTDATA_H
#define COMMONABSTRACTDATA_H

#include <memory>
#include <list>
#include "../interface/ICommonAbstractData.h"
#include "../interface/IParameters.h"

class CommonAbstractData : public ICommonAbstractData
{
public:
    CommonAbstractData(const std::list<std::shared_ptr<IOperator>> &array = {});
    bool hasOperand(const IOperator &, const IParameters &) const noexcept override;

protected:
    void addSupportedOperand(const std::shared_ptr<IOperator> &);
    void addSupportedOperand(const std::list<std::shared_ptr<IOperator>> &);
    void addSupportedOperand(const std::initializer_list<std::shared_ptr<IOperator>> &);

private:
    std::list<std::shared_ptr<IOperator>> m_operand;
};

#endif // COMMONABSTRACTDATA_H
