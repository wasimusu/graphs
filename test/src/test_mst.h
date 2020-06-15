#include "../../src/graphs.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(prim_mst, random_graph) {
    graph *graph1 = new edgeList;

    bool a = graph1->add_edge({1, 2, 3});
    bool b = graph1->add_edge({1, 3, 4});
    bool c = graph1->add_edge({4, 2, 6});
    bool d = graph1->add_edge({5, 2, 2});
    bool e = graph1->add_edge({2, 3, 5});
    bool f = graph1->add_edge({3, 5, 7});
    EXPECT_EQ(a && b && c && d && e && f, 1);

    int res_prim = mst_prim(graph1);
    int res_kruskal = mst_kruskal(graph1);
    EXPECT_EQ(res_kruskal, res_prim);
}