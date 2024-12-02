#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Example {
    public:
        int foo() {
            return 1;
        }

};

class TestFixture : public testing::Test
{
    public:
        TestFixture(){
            ex = new Example();
        }

        ~TestFixture(){}

        void SetUp() {

        }

        void TearDown() {

        }

    Example *ex;
};

TEST_F(TestFixture, test1) {
    ASSERT_EQ(1, ex->foo());
}

TEST_F(TestFixture, test2) {
    ASSERT_NE(0, ex->foo());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}