cmake_minimum_required(VERSION 3.0)
project(graphs)

set(CMAKE_CXX_STANDARD 11)

add_executable(exe
        src/main.cpp
        src/graphs.h
        )


add_executable(top_demo sample/topological_sort_demo.cpp)
add_executable(mst_demo sample/mst_demo.cpp)
add_executable(dijkstra_demo sample/distance_demo.cpp)

add_subdirectory(test/googletest)
include_directories(test/googletest/googletest/include)

add_executable(sample_test test/test1.cpp)
add_executable(sample_test2 test/test1.cpp test/test_main.cpp)

target_link_libraries(sample_test gtest gtest_main)
target_link_libraries(sample_test2 gtest gtest_main)