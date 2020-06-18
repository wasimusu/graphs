# Setup benchmark
add_subdirectory(benchmark)
include_directories(benchmark/include)

add_executable(bench_edgeList src/bench_data_structures.cpp)
target_link_libraries(bench_edgeList benchmark)

add_executable(bench_distance src/bench_distance.cpp)
target_link_libraries(bench_distance benchmark)

add_executable(bench_mst src/bench_mst.cpp)
target_link_libraries(bench_mst benchmark)

add_executable(bench_traverse src/bench_traverse.cpp)
target_link_libraries(bench_traverse benchmark)

add_executable(bench_topsort src/bench_topsort.cpp)
target_link_libraries(bench_topsort benchmark)

add_executable(bench_findunion src/bench_findunion.cpp)
target_link_libraries(bench_findunion benchmark)