#include "struccore.h"
#include <sstream>
#include <vector>
#include <utility>

using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

namespace
{
    //unordered_map<string, type_index> cppType;
}
unsigned Indentation = 0;
std::vector<std::pair<std::string, std::type_index> > cppType = {
    {"std::string", typeid(std::string)},
    {"int64_t", typeid(int64_t)},
    {"char", typeid(char)},
    {"unsigned", typeid(unsigned)},
    {"double", typeid(double)},
    {"void", typeid(void)},
    {"bool", typeid(bool)}
};
