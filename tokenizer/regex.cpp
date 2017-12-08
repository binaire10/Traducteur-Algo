#include "regex.h"
#include <iostream>
#include <memory>

#define PCRE2_CODE_UNIT_WIDTH 8

binaire::regex::regex(const std::string &pattern)
{
    int errornumber;
    PCRE2_SIZE erroroffset;
    m_compiledRegex = std::shared_ptr<pcre2_code>(pcre2_compile(
            reinterpret_cast<PCRE2_SPTR>(pattern.data()),               /* the pattern */
                    PCRE2_ZERO_TERMINATED, /* indicates pattern is zero-terminated */
                    0,                     /* default options */
                    &errornumber,          /* for error number */
                    &erroroffset,          /* for error offset */
                    NULL),[](pcre2_code *ptr){
        pcre2_code_free(ptr);
    });
    if (m_compiledRegex == nullptr)
    {
        PCRE2_UCHAR buffer[256];
        pcre2_get_error_message(errornumber, buffer, sizeof(buffer));
        printf("PCRE2 compilation failed at offset %d: %s\n", (int)erroroffset, buffer);
    }
}

bool binaire::regex_match(std::string::const_iterator begin, std::string::const_iterator end, regex &regex1)
{
    std::shared_ptr<pcre2_match_data> matchData(pcre2_match_data_create(1ul, nullptr), [](pcre2_match_data *ptr){pcre2_match_data_free(ptr);});
    int err = pcre2_match(regex1.m_compiledRegex.get(), reinterpret_cast<PCRE2_SPTR8>(&*begin), -1, 0, 0, matchData.get(), nullptr);
    return err > 0;
}
std::pair<std::string::const_iterator, std::string::const_iterator> binaire::regex_find(std::string::const_iterator begin, std::string::const_iterator end, regex &regex1)
{
    std::shared_ptr<pcre2_match_data> matchData(pcre2_match_data_create(1ul, nullptr), [](pcre2_match_data *ptr){pcre2_match_data_free(ptr);});
    int err = pcre2_match(regex1.m_compiledRegex.get(), reinterpret_cast<PCRE2_SPTR8>(&*begin), std::distance(begin, end), 0, 0, matchData.get(), nullptr);
    if(err <= 0)
        return {begin, begin};
    PCRE2_SIZE *ovector;
    ovector = pcre2_get_ovector_pointer(matchData.get());
    return {begin + ovector[0], begin + ovector[1]};
};
