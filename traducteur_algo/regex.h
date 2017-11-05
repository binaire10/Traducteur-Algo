#ifndef TRADUCTEUR_ALGO_REGEX_H
#define TRADUCTEUR_ALGO_REGEX_H

#include <string>
#include <memory>

#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

namespace binaire
{
    class regex;
    bool regex_match(std::string::const_iterator begin, std::string::const_iterator end, regex &regex1);
    std::pair<std::string::const_iterator, std::string::const_iterator> regex_find(std::string::const_iterator begin, std::string::const_iterator end, regex &regex1);
    class regex
    {
    public:
        regex(const std::string &pattern);
    private:
        std::shared_ptr<pcre2_code> m_compiledRegex;
        friend bool regex_match(std::string::const_iterator begin, std::string::const_iterator end, regex &regex1);
        friend std::pair<std::string::const_iterator, std::string::const_iterator> regex_find(std::string::const_iterator begin, std::string::const_iterator end, regex &regex1);
    };
}
#undef PCRE2_CODE_UNIT_WIDTH

#endif //TRADUCTEUR_ALGO_REGEX_H
