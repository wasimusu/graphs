#include "../../src/graphs.h"
#include "gtest/gtest.h"

TEST(dijkstra, linear_graph) {

    edgeList edgeList;
    int num_nodes = 10;
    for (int i = 0; i < num_nodes - 1; i++) {
        edgeList.add_edge({i, i + 1, 1});
    }

    for (int start = 0; start < num_nodes; start++) {
        for (int end = 0; end < num_nodes; end++) {
            int res = dijkstra_shortest_distance(edgeList, start, end);
            std::cout << res << "\t" << abs(end - start) << "\n";
            EXPECT_EQ(res, abs(end - start));
        }
    }

}

TEST(dijkstra, directed_graph) {

}

TEST(dijkstra, undirected_graph) {

}