#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Example {
    public:
        int foo() {
            return 1;
        }

};

TEST(exampleTest, test2) {
    Example ex;
    ASSERT_EQ(1, ex.foo());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}