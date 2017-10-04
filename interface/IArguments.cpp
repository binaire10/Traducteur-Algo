#include "IArguments.h"

bool IArguments::isConvertible(const IArguments &arg) const noexcept
{
    if(arg.size() != size())
        return false;
    for(std::size_t i(0) ; i<size() ; ++i)
        if(!at(i).isConvertible(arg.at(i)))
            return false;
    return true;
}

bool IArguments::equals(const IArguments &arg) const noexcept
{
    if(arg.size() != size())
        return false;
    for(std::size_t i(0) ; i<size() ; ++i)
        if(!at(i).equals(arg.at(i)))
            return false;
    return true;
}
