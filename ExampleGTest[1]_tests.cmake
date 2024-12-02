add_test( testFixtureDummy.dummyInt /home/ewic/Documents/smart-pointers/ExampleGTest [==[--gtest_filter=testFixtureDummy.dummyInt]==] --gtest_also_run_disabled_tests)
set_tests_properties( testFixtureDummy.dummyInt PROPERTIES WORKING_DIRECTORY /home/ewic/Documents/smart-pointers SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( ExampleGTest_TESTS testFixtureDummy.dummyInt)
