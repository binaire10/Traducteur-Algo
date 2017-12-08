#include "TokenizerIterator.h"

binaire::TokenizerIterator::TokenizerIterator(const std::string::const_iterator &begin,
                                              const std::string::const_iterator &end, const binaire::regex &reg) : m_result(begin, begin), m_range(begin, end), m_regex(reg)
{}

bool binaire::TokenizerIterator::next()
{
    if(m_result.second==m_range.second)
        return false;
    // t.second!=value.end()?t.second:t.second+1
    m_result  = regex_find(m_result.second, m_range.second, m_regex);
    return  m_result.first != m_result.second;
}

void binaire::TokenizerIterator::setResult(const binaire::TokenizerIterator::token_type &token)
{
    m_result = token;
}

const binaire::TokenizerIterator::token_type &binaire::TokenizerIterator::result() const
{
    return m_result;
}

const binaire::regex &binaire::TokenizerIterator::getRegex() const
{
    return m_regex;
}
