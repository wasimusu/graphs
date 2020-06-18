cmake_minimum_required(VERSION 3.0)
project(graphs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -fsanitize=address -pg -g")

# Setup tests
add_subdirectory(test)
add_subdirectory(benchmark)

add_executable(graphs src/main.cpp)

# Sample codes
add_executable(top_demo sample/topological_sort_demo.cpp)
add_executable(mst_demo sample/mst_demo.cpp)
add_executable(dijkstra_demo sample/dijkstra_demo.cpp)
add_executable(bellman_ford_demo sample/bellman_ford_demo.cpp)