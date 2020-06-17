#pragma once

#include "../../src/graphs.h"
#include "gtest/gtest.h"

TEST(mst, random_graph) {
    graph *graph1 = new edgeList;

    bool a = graph1->add_edge({1, 2, 3});
    bool b = graph1->add_edge({1, 3, 4});
    bool c = graph1->add_edge({4, 2, 6});
    bool d = graph1->add_edge({5, 2, 2});
    bool e = graph1->add_edge({2, 3, 5});
    bool f = graph1->add_edge({3, 5, 7});
    EXPECT_EQ(a && b && c && d && e && f, 1);

    int res_prim = mst_prim(graph1);
//    int res_kruskal = mst_kruskal(graph1);
//    EXPECT_EQ(res_kruskal, res_prim);
//    EXPECT_EQ(res_kruskal, 15);
}

TEST(mst, random_graph2) {
//    https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

    edgeList edgeList(false);
    bool a = edgeList.add_edge(0, 1, 4);
    bool b = edgeList.add_edge(0, 3, 1);
    bool c = edgeList.add_edge(1, 2, 5);
    bool d = edgeList.add_edge(2, 3, 2);
    bool e = edgeList.add_edge(0, 2, 3);
    EXPECT_EQ(a && b && c && d && e, 1);

    int res_prim = mst_prim(&edgeList);
    int res_kruskal = mst_kruskal(&edgeList);
//    EXPECT_EQ(res_prim, 7);
//    EXPECT_EQ(res_kruskal, res_prim);

}


TEST(mst, random_graph3) {
    graph *graph1 = new edgeList;

    bool a = graph1->add_edge({0, 1, 4});
    bool b = graph1->add_edge({0, 2, 3});
    bool c = graph1->add_edge({0, 3, 5});
    bool d = graph1->add_edge({0, 4, 1});
    bool e = graph1->add_edge({1, 2, 2});
    bool f = graph1->add_edge({2, 3, 6});
    bool g = graph1->add_edge({3, 4, 7});
    EXPECT_EQ(a && b && c && d && e && f && g, 1);

    int res_prim = mst_prim(graph1);
    int res_kruskal = mst_kruskal(graph1);
//    EXPECT_EQ(res_kruskal, 11);
//    EXPECT_EQ(res_kruskal, res_prim);
}
