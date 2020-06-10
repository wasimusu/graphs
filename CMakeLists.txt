cmake_minimum_required(VERSION 3.0)
project(graphs)

set(CMAKE_CXX_STANDARD 11)

add_executable(exe
        src/main.cpp
        src/graphs.h
        )


add_executable(top_demo sample/topological_sort_demo.cpp)
add_executable(mst_demo sample/mst_demo.cpp)
add_executable(dijkstra_demo sample/dijkstra_demo.cpp)

#add_subdirectory(test/googletest)
#include_directories(test/googletest/googletest/include)
#
#add_executable(test test/mst_test.cpp)
#target_link_libraries(test gtest gtest_main)

