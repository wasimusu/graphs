# Setup benchmark
add_subdirectory(benchmark)
include_directories(benchmark/include)

add_executable(bench_edgeList src/bench_edgeList.cpp)
target_link_libraries(bench_edgeList benchmark)

add_executable(bench_distance src/bench_distance.cpp)
target_link_libraries(bench_distance benchmark)

add_executable(bench_mst src/bench_mst.cpp)
target_link_libraries(bench_mst benchmark)
