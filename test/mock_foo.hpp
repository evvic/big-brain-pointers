#include "foo_if.hpp"
#include <gmock/gmock.h>

class MockFoo : public fooIf {
    public:
        MOCK_METHOD(int, fooInt, (const std::string& str), (override));

};
