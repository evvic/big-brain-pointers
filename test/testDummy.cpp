#include <iostream>
#include <gtest/gtest.h>
#include "dummy.hpp"
#include <memory>

class testFixtureDummy : public testing::Test {
    public:
    testFixtureDummy(){
        mTestDummy = std::make_unique<dummy>();
    }
    ~testFixtureDummy(){}

    void SetUp() {

    }

    void TearDown() {

    }

    std::unique_ptr<dummy> mTestDummy;
};

TEST_F(testFixtureDummy, dummyInt) {
    std::string str {"heywhatsuphello"};
    int result = mTestDummy->dummyInt(str);
    ASSERT_EQ(str.size(), result);
}

// TEST_F(TestFixture, test2) {
//     ASSERT_NE(0, ex->foo());
// }
