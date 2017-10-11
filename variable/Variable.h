#ifndef TRADUCTEUR_ALGO_VARIABLE_H
#define TRADUCTEUR_ALGO_VARIABLE_H

#include <memory>
#include <string>
#include "../type/AbstractDataType.h"

class Variable
{
public:
    Variable(const std::string &name, const std::shared_ptr<AbstractDataType> &variable);

private:
    std::string m_name;
    std::shared_ptr<AbstractDataType> m_type;
};

#endif //TRADUCTEUR_ALGO_VARIABLE_H
