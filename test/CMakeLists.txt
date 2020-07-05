# Setup tests
add_subdirectory(googletest)
include_directories(googletest/googletest/include)

# All tests
add_executable(tests src/gtest_main.cpp)
target_link_libraries(tests gtest gtest_main)

# Individual tests
add_executable(distance_test src/test_distance.h)
target_link_libraries(distance_test gtest gtest_main)

add_executable(edge_test src/test_edgeList.h)
target_link_libraries(edge_test gtest gtest_main)

add_executable(topsort_test src/test_topological_sort.h)
target_link_libraries(topsort_test gtest gtest_main)

add_executable(traverse_test src/test_traverse.h)
target_link_libraries(traverse_test gtest gtest_main)

add_executable(mst_test src/test_mst.h)
target_link_libraries(mst_test gtest gtest_main)

add_executable(adjMatrix_test src/test_adjancencyMatrix.h)
target_link_libraries(adjMatrix_test gtest gtest_main)

add_executable(adjList_test src/test_adjacencyList.h)
target_link_libraries(adjList_test gtest gtest_main)

add_executable(unionfind_test src/test_unionfind.h)
target_link_libraries(unionfind_test gtest gtest_main)