#include <iostream>
#include <gtest/gtest.h>
#include "dummy.hpp"
#include <memory>
#include "mock_foo.hpp"

class testFixtureDummy : public testing::Test {
    public:
    testFixtureDummy(){
        // The MOCK object mFoo, is used to isolate unit testing
        // as there can be many factors at play when using
        // interfaces
        mTestDummy = std::make_unique<dummy>(mFoo);
    }
    ~testFixtureDummy(){}

    void SetUp() {

    }

    void TearDown() {

    }

    MockFoo mFoo;

    std::unique_ptr<dummy> mTestDummy;
};

TEST_F(testFixtureDummy, dummyInt) {
    std::string str {"heywhatsuphello"};

    EXPECT_CALL(mFoo, fooInt(str)).Times(1).WillOnce(testing::Return(str.size()));
    int result = mTestDummy->dummyInt(str);

    ASSERT_EQ(str.size(), result);
}

// TEST_F(TestFixture, test2) {
//     ASSERT_NE(0, ex->foo());
// }
