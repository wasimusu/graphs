# Setup benchmark
add_subdirectory(benchmark)
include_directories(benchmark/include)

add_executable(bench_edgeList src/bench_edgeList.cpp)
target_link_libraries(bench_edgeList benchmark)
