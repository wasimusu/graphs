cmake_minimum_required(VERSION 3.0)
project(graphs_test)

set(CMAKE_CXX_STANDARD 17)


# Setup tests
add_subdirectory(googletest)
include_directories(googletest/googletest/include)

# All tests
add_executable(tests src/gtest_main.cpp)
target_link_libraries(tests gtest gtest_main)

# Individual tests
add_executable(distance_test src/test_distance.h)
target_link_libraries(distance_test gtest gtest_main)

add_executable(edge_test src/test_edgeList.h)
target_link_libraries(edge_test gtest gtest_main)
