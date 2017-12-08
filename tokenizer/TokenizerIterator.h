#ifndef TRADUCTEUR_ALGO_TOKENIZERITERATOR_H
#define TRADUCTEUR_ALGO_TOKENIZERITERATOR_H

#include "regex.h"

namespace binaire
{
    class TokenizerIterator
    {
    public:
        using token_type = std::pair<std::string::const_iterator, std::string::const_iterator>;
        TokenizerIterator(const std::string::const_iterator &begin, const std::string::const_iterator &end, const regex &reg);

        bool next();
        void setResult(const token_type &token);
        const token_type &result() const;
        const regex &getRegex() const;

    private:
        token_type m_result;
        token_type m_range;
        regex m_regex;
    };
}


#endif //TRADUCTEUR_ALGO_TOKENIZERITERATOR_H
