#include <iostream>
#include <cassert>
#include "TokenizerIterator.h"

using namespace std;

int main()
{
    binaire::regex reg("<-|\\b\\w+\\b|\"(?:\\\\[^\\n\\r]|[^\"\\n\\r\\\\])*?\"|'(?:\\\\[^\\n\\r]|[^'\\n\\r\\\\])*?'|\\/\\*[\\w\\W]*?\\*\\/|\\/\\/.*|\\((?:(?R)|[ ,])*?\\)|\\[(?:(?R)|[ \\t])*?\\]|[^ \\t\\r\\n]");
    std::string value =
            "algorithme Test\n"
                    "debut\n"
                    "\tdeclarer var1:entier_naturel;\n"
                    "\tsaisir(var1);\n"
                    "\tsi(modulo(var1, 3))\n";
    binaire::TokenizerIterator token(value.begin(), value.end(), reg);

    assert(token.next());
    assert(string(token.result().first, token.result().second) == "algorithme");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "Test");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "debut");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "declarer");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "var1");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == ":");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "entier_naturel");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == ";");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "saisir");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "(var1)");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == ";");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "si");
    assert(token.next());
    assert(string(token.result().first, token.result().second) == "(modulo(var1, 3))");
    assert(!token.next());

    return 0;
}