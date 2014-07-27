
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

/**
 * @brief Run gtest based tests
 *
 * This function setup the GoogleTest framework and run tests.
 * This function will exit after completing all the tests.
 */
int main()
{
    int argc = 1;
    char *argv[1];
    char name[] = "none";
    bool tests_failed = 0;

    argv[0] = name;

    ::testing::InitGoogleTest(&argc, argv);
    tests_failed = RUN_ALL_TESTS();
    cout << "Testing " << (tests_failed ? "failed\n" : "passed\n");

    exit(0);
}

