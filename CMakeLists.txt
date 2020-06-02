cmake_minimum_required(VERSION 3.14)
project(graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(graphrepr
        src/main.cpp
        src/graphs.h
        )

add_executable(demo1 sample/topological_sort_demo.cpp)