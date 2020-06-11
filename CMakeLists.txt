cmake_minimum_required(VERSION 3.0)
project(graphs)

set(CMAKE_CXX_STANDARD 17)

# Setup tests
add_subdirectory(test/googletest)
include_directories(test/googletest/googletest/include)

add_executable(exe
        src/main.cpp
        src/graphs.h
        )

# Sample codes
add_executable(top_demo sample/topological_sort_demo.cpp)
add_executable(mst_demo sample/mst_demo.cpp)
add_executable(dijkstra_demo sample/distance_demo.cpp)


# All tests
#add_executable(alltests
#        test/src/test_main.cpp
#        test/src/edgeList.cpp
#        test/src/adjacencyList.cpp
#        test/src/adjancencyMatrix.cpp
#        test/src/distance.cpp
#        test/src/mst.cpp
#        test/src/topological_sort.cpp
#        test/src/traverse.cpp
#        )

#target_link_libraries(alltests gtest gtest_main)

# Individual tests
add_executable(distance_test test/src/distance.cpp)
target_link_libraries(distance_test gtest gtest_main)