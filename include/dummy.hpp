#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <string>
#include "foo_if.hpp"

class dummy
{
private:
    /* data */
public:
    dummy(fooIf& f) : mfoo(f) {};
    ~dummy();
    int dummyInt(const std::string& str);
    fooIf& mfoo;
};


#endif /* DUMMY_HPP */