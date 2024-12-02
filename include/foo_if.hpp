#ifndef FOO_IF_HPP
#define FOO_IF_HPP
#include <string>

class fooIf {
    public:
        virtual int fooInt(const std::string& str) = 0;
};

#endif /* FOO_IF_HPP */
