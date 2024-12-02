#ifndef FOO_HPP
#define FOO_HPP
#include "foo_if.hpp"

class foo : public fooIf {
    public:
       int fooInt(const std::string& str);
};

#endif /* FOO_HPP */
