#pragma once

#include "../../src/graphs.h"
#include "gtest/gtest.h"
#include <vector>
#include <iostream>

using namespace std;

TEST(topsort, linear_graph) {
    edgeList edgeList;
    bool a = edgeList.add_edge({0, 1});
    bool b = edgeList.add_edge({1, 2});
    bool c = edgeList.add_edge({2, 3});
    bool d = edgeList.add_edge({3, 4});
    EXPECT_EQ(a && b && c && d, 1);

    vector<int> expected_result = {4, 3, 2, 1, 0};
    vector<int> actual_result;
    topological_sort(&edgeList, actual_result);

    EXPECT_EQ(expected_result, actual_result);
}

TEST(topsort, random_graph) {
    graph *graph1 = new edgeList;

    bool a = graph1->add_edge({1, 0});
    bool b = graph1->add_edge({2, 0});
    bool c = graph1->add_edge({3, 1});
    bool d = graph1->add_edge({3, 2});
    EXPECT_EQ(a && b && c && d, 1);

    vector<int> expected_result = {0, 2, 1, 3};
    vector<int> actual_result;
    topological_sort(graph1, actual_result);

    EXPECT_EQ(expected_result, actual_result);
    delete graph1;
}