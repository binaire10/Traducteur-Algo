#include "IParameters.h"

bool IParameters::isConvertible(const IParameters &arg) const noexcept
{
    if(arg.size() != size())
        return false;
    for(std::size_t i(0) ; i<size() ; ++i)
        if(!at(i).isConvertible(arg.at(i)))
            return false;
    return true;
}

bool IParameters::equals(const IParameters &arg) const noexcept
{
    if(arg.size() != size())
        return false;
    for(std::size_t i(0) ; i<size() ; ++i)
        if(!at(i).equals(arg.at(i)))
            return false;
    return true;
}
