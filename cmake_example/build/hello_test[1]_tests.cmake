add_test([=[HelloTest.BasicAssertions]=]  /Users/leonardshin/Documents/c_prog/find_k_closest_elements/cmake_example/build/hello_test [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY /Users/leonardshin/Documents/c_prog/find_k_closest_elements/cmake_example/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  hello_test_TESTS HelloTest.BasicAssertions)
