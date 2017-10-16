#include "ParametersUtility.h"

bool isConvertibles(const std::list<std::shared_ptr<AbstractDataType> > &parametersType, const std::list<std::shared_ptr<Expressionable> > &expressionArguments)
{
    if(parametersType.size() != expressionArguments.size())
        return false;
    std::list<std::shared_ptr<AbstractDataType>>::const_iterator itParameter = parametersType.begin();
    std::list<std::shared_ptr<Expressionable>>::const_iterator expressionArgument = expressionArguments.begin();
    std::list<std::shared_ptr<Expressionable>>::const_iterator endExpression = expressionArguments.end();
    while(expressionArgument!=endExpression)
    {
        if(!(*itParameter)->isConvertible(*(*expressionArgument)->result()))
            return false;
        (++itParameter, ++expressionArgument);
    }
    return true;
}

bool isEquals(const std::list<std::shared_ptr<AbstractDataType>> &parametersType, const std::list<std::shared_ptr<Expressionable>> &expressionArguments)
{
    if(parametersType.size() != expressionArguments.size())
        return false;
    std::list<std::shared_ptr<AbstractDataType>>::const_iterator itParameter = parametersType.begin();
    std::list<std::shared_ptr<Expressionable>>::const_iterator expressionArgument = expressionArguments.begin();
    std::list<std::shared_ptr<Expressionable>>::const_iterator endExpression = expressionArguments.end();
    while(expressionArgument!=endExpression)
    {
        if(!(*itParameter)->equals(*(*expressionArgument)->result()))
            return false;
        (++itParameter, ++expressionArgument);
    }
    return true;
}

bool isEquals(const std::list<std::shared_ptr<AbstractDataType> > &parametersType, const std::list<std::shared_ptr<AbstractDataType> > &expressionArguments)
{
    if(parametersType.size() != expressionArguments.size())
        return false;
    std::list<std::shared_ptr<AbstractDataType>>::const_iterator itParameter = parametersType.begin();
    std::list<std::shared_ptr<AbstractDataType>>::const_iterator expressionArgument = expressionArguments.begin();
    std::list<std::shared_ptr<AbstractDataType>>::const_iterator endExpression = expressionArguments.end();
    while(expressionArgument!=endExpression)
    {
        if(!(*itParameter)->isConvertible(**expressionArgument))
            return false;
        (++itParameter, ++expressionArgument);
    }
    return true;
}

bool isConvertibles(const std::list<std::shared_ptr<AbstractDataType> > &parametersType, const std::list<std::shared_ptr<AbstractDataType> > &expressionArguments)
{
    if(parametersType.size() != expressionArguments.size())
        return false;
    std::list<std::shared_ptr<AbstractDataType>>::const_iterator itParameter = parametersType.begin();
    std::list<std::shared_ptr<AbstractDataType>>::const_iterator expressionArgument = expressionArguments.begin();
    std::list<std::shared_ptr<AbstractDataType>>::const_iterator endExpression = expressionArguments.end();
    while(expressionArgument!=endExpression)
    {
        if(!(*itParameter)->equals(**expressionArgument))
            return false;
        (++itParameter, ++expressionArgument);
    }
    return true;
}
