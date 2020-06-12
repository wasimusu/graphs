#include "gtest/gtest.h"
#include "test_distance.h"
#include "test_edgeList.h"

int main(int argc, char **argv) {
    std::cout << "Running tests. Brace yourself" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}