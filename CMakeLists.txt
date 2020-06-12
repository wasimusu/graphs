cmake_minimum_required(VERSION 3.0)
project(graphs)

set(CMAKE_CXX_STANDARD 17)

# Setup tests
add_subdirectory(test/googletest)
include_directories(test/googletest/googletest/include)

add_executable(graphs
        src/main.cpp
        src/graphs.h
        )

# Sample codes
add_executable(top_demo sample/topological_sort_demo.cpp)
add_executable(mst_demo sample/mst_demo.cpp)
add_executable(dijkstra_demo sample/dijkstra_demo.cpp)
add_executable(bellman_ford_demo sample/bellman_ford_demo.cpp)


# All tests
add_executable(tests test/src/gtest_main.cpp)

target_link_libraries(tests gtest gtest_main)

# Individual tests
add_executable(distance_test test/src/test_distance.h)
target_link_libraries(distance_test gtest gtest_main)

add_executable(edge_test test/src/test_edgeList.h)
target_link_libraries(edge_test gtest gtest_main)
