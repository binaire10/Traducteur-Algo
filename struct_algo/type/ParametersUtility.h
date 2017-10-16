#ifndef ABSTRACTDATAPARAMETERS_H
#define ABSTRACTDATAPARAMETERS_H

#include <memory>
#include "AbstractDataType.h"
#include "../interface/Expressionable.h"
#include <list>

bool isEquals(const std::list<std::shared_ptr<AbstractDataType>> &parametersType, const std::list<std::shared_ptr<Expressionable>> &expressionArguments);
bool isConvertibles(const std::list<std::shared_ptr<AbstractDataType>> &parametersType, const std::list<std::shared_ptr<Expressionable>> &expressionArguments);

bool isEquals(const std::list<std::shared_ptr<AbstractDataType>> &parametersType, const std::list<std::shared_ptr<AbstractDataType>> &expressionArguments);
bool isConvertibles(const std::list<std::shared_ptr<AbstractDataType>> &parametersType, const std::list<std::shared_ptr<AbstractDataType>> &expressionArguments);

#endif // ABSTRACTDATAPARAMETERS_H
