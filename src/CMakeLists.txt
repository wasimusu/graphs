set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.10)

add_library(graphlib "graphs.h")
target_include_directories(graphlib PUBLIC .)

add_executable(graphs main.cpp)

set_target_properties(graphlib PROPERTIES LINKER_LANGUAGE CXX)
