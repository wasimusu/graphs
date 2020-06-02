cmake_minimum_required(VERSION 3.14)
project(graphs)

set(CMAKE_CXX_STANDARD 11)

add_executable(graphs src/main.cpp)

add_executable(graphrepr src/graph.cpp)