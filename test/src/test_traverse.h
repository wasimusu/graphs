#pragma once

#include "../../src/graphs.h"
#include "gtest/gtest.h"

class traversalTest1 : public ::testing::Test {
public:
    virtual void SetUp() {
        graph.add_edge(0, 1);
        graph.add_edge(0, 2);
        graph.add_edge(1, 3);
        graph.add_edge(1, 4);
        graph.add_edge(2, 5);
        graph.add_edge(2, 6);
        graph.add_edge(3, 7);
        graph.add_edge(3, 8);
        graph.add_edge(4, 9);
        graph.add_edge(4, 10);
        graph.add_edge(5, 11);
    }

    edgeList graph;
};

TEST_F(traversalTest1, level_order) {
    std::vector<std::vector<int>> actual_level_order, expected_level_order = {{0},
                                                                              {1, 2},
                                                                              {3, 4, 5, 6},
                                                                              {7, 8, 9, 10, 11}};
    level_order_traversal(graph, 0, actual_level_order);
    auto result = equal(expected_level_order.begin(), expected_level_order.end(), actual_level_order.begin());
    EXPECT_EQ(result, true);
}

TEST_F(traversalTest1, bfs) {
    std::vector<int> actual_bfs, expected_bfs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    bfs(graph, 0, actual_bfs);
    EXPECT_EQ(expected_bfs, actual_bfs);
}

TEST_F(traversalTest1, dfs) {
    std::vector<int> actual_dfs, expected_dfs = {0, 2, 6, 5, 11, 1, 4, 10, 9, 3, 8, 7};
    dfs(graph, 0, actual_dfs);
    EXPECT_EQ(expected_dfs, actual_dfs);
}


class traversalTest2 : public ::testing::Test {
public:
    virtual void SetUp() {
        graph.add_edge(0, 1);
        graph.add_edge(1, 2);
        graph.add_edge(2, 3);
        graph.add_edge(3, 4);
        graph.add_edge(4, 5);
        graph.add_edge(5, 6);
        graph.add_edge(6, 7);
        graph.add_edge(7, 8);
        graph.add_edge(8, 9);
        graph.add_edge(9, 10);
        graph.add_edge(10, 11);
    }

    edgeList graph;
};


TEST_F(traversalTest2, level_order) {
    std::vector<std::vector<int>> actual_level_order, expected_level_order = {{0},
                                                                              {1},
                                                                              {2},
                                                                              {3},
                                                                              {4},
                                                                              {5},
                                                                              {6},
                                                                              {7},
                                                                              {8},
                                                                              {9},
                                                                              {10},
                                                                              {11}};
    level_order_traversal(graph, 0, actual_level_order);
    auto result = equal(expected_level_order.begin(), expected_level_order.end(), actual_level_order.begin());
    EXPECT_EQ(result, true);
}

TEST_F(traversalTest2, bfs) {
    std::vector<int> actual_bfs, expected_bfs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    bfs(graph, 0, actual_bfs);
    EXPECT_EQ(expected_bfs, actual_bfs);
}

TEST_F(traversalTest2, dfs) {
    std::vector<int> actual_dfs, expected_dfs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    dfs(graph, 0, actual_dfs);
    EXPECT_EQ(expected_dfs, actual_dfs);
}

class traversalTest3 : public ::testing::Test {
public:
    virtual void SetUp() {
        graph.add_edge(0, 1, 4);
        graph.add_edge(0, 2, 2);
        graph.add_edge(1, 2, 5);
        graph.add_edge(1, 3, 10);
        graph.add_edge(2, 4, 3);
        graph.add_edge(4, 3, 4);
        graph.add_edge(3, 5, 11);
    }

    edgeList graph;
};


TEST_F(traversalTest3, level_order) {
    std::vector<std::vector<int>> actual_level_order, expected_level_order = {{0},
                                                                              {1},
                                                                              {2},
                                                                              {3},
                                                                              {4},
                                                                              {5},
                                                                              {6},
                                                                              {7},
                                                                              {8},
                                                                              {9},
                                                                              {10},
                                                                              {11}};
    level_order_traversal(graph, 0, actual_level_order);
    auto result = equal(expected_level_order.begin(), expected_level_order.end(), actual_level_order.begin());
//    EXPECT_EQ(result, true);
}

TEST_F(traversalTest3, bfs) {
    std::vector<int> actual_bfs, expected_bfs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    bfs(graph, 0, actual_bfs);
//    EXPECT_EQ(expected_bfs, actual_bfs);
}

TEST_F(traversalTest3, dfs) {
    std::vector<int> actual_dfs, expected_dfs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    dfs(graph, 0, actual_dfs);
//    EXPECT_EQ(expected_dfs, actual_dfs);
}