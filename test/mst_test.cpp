//#include <iostream>
#include "../src/graphs.h"
//#include <vector>
//#include "gtest/gtest.h"

using namespace std;

//TEST(mst, prim_mst) {
//    graph *graph1 = new edgeList;
//
//    bool a = graph1->add_edge({1, 2, 3});
//    bool b = graph1->add_edge({1, 3, 4});
//    bool c = graph1->add_edge({4, 2, 6});
//    bool d = graph1->add_edge({5, 2, 2});
//    bool e = graph1->add_edge({2, 3, 5});
//    bool f = graph1->add_edge({3, 5, 7});
//    EXPECT_EQ(a && b && c && d && e && f, true);
//
//    auto n = dynamic_cast<edgeList *>(graph1)->get_num_nodes();
//    EXPECT_EQ(n, 5);
//
//    int result = mst_prim(graph1);
//    EXPECT_EQ(result, 15);
//}
