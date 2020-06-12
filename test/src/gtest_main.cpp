#include "gtest/gtest.h"
#include "test_distance.h"
#include "test_edgeList.h"

int main(int argc, char **argv) {
    std::cout << "Running tests. Brace yourself\n" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    auto status = RUN_ALL_TESTS();
    if (!status) std::cout << "\nAll tests passed!" << std::endl;
    return status;
}