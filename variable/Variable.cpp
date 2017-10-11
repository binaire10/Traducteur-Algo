#include "Variable.h"

Variable::Variable(const std::string &name, const std::shared_ptr<AbstractDataType> &type) : m_name(name), m_type(type)
{}
