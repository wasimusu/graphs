#include "gtest/gtest.h"

int main(int argc, char **argv) {
    std::cout << "Running tests. Brace yourself" << std::endl;
    ::testing::InitGoogleTest(&argc, argv);

    auto i = RUN_ALL_TESTS();
    std::cout << i << std::endl;
    return i;
}