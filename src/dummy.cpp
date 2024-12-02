#include "dummy.hpp"

dummy::dummy(/* args */)
{
    // hello world
}

dummy::~dummy()
{
}

int dummy::dummyInt(const std::string& str) {
    return str.length();
}
