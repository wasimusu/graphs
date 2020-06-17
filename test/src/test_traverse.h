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
    std::cout << "Kaha aaiyo ta" << std::endl;
    for (auto &level: actual_level_order) {
        for (const auto node: level) {
            std::cout << node << "\t";
        }
        std::cout << std::endl << std::flush;
    }
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
    std::cout << "Kaha aaiyo ta" << std::endl;
    for (auto &level: actual_level_order) {
        for (const auto node: level) {
            std::cout << node << "\t";
        }
        std::cout << std::endl << std::flush;
    }
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


TEST(bfs, linear_graph) {

    edgeList edgeList(false);
    int num_nodes = 10;
    for (int i = 0; i < num_nodes - 1; i++) {
        edgeList.add_edge({i, i + 1, 1});
    }

//    auto res = dijkstra_shortest_distance(edgeList, 0);
//    for(int r: res) std::cout << r << "\t"; cout << endl;

    for (int start = 0; start < num_nodes; start++) {
        std::cout << start << endl;
        auto res = dijkstra_shortest_distance(edgeList, start);
//        for (int end = 0; end < num_nodes; end++) {
//            std::cout << res[end] << "\t" << abs(end - start) << endl;
//            EXPECT_EQ(res[end], abs(end - start));
//        }
    }
}

TEST(bfs, directed_graph) {
    //Test case source: https://en.wikipedia.org/wiki/Shortest_path_problem

    edgeList edgeList(true);
    edgeList.add_edge(0, 1, 4);
    edgeList.add_edge(0, 2, 2);
    edgeList.add_edge(1, 2, 5);
    edgeList.add_edge(1, 3, 10);
    edgeList.add_edge(2, 4, 3);
    edgeList.add_edge(4, 3, 4);
    edgeList.add_edge(3, 5, 11);

    auto actual_distance = dijkstra_shortest_distance(edgeList, 0);
    std::vector<int> expected_distance = {0, 4, 2, 9, 5, 20};
    EXPECT_EQ(expected_distance, actual_distance);
}

TEST(bfs, undirected_graph) {
    // Test case source: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

    edgeList edgeList(false);
    edgeList.add_edge({0, 1, 4});
    edgeList.add_edge({0, 7, 8});
    edgeList.add_edge({1, 7, 11});
    edgeList.add_edge({1, 2, 8});
    edgeList.add_edge({7, 8, 7});
    edgeList.add_edge({7, 6, 1});
    edgeList.add_edge({8, 6, 6});
    edgeList.add_edge({6, 5, 2});
    edgeList.add_edge({5, 4, 10});
    edgeList.add_edge({5, 3, 14});
    edgeList.add_edge({5, 2, 4});
    edgeList.add_edge({8, 2, 2});
    edgeList.add_edge({3, 2, 7});
    edgeList.add_edge({3, 4, 9});

    auto actual_distance = dijkstra_shortest_distance(edgeList, 0);
    std::vector<int> expected_distance = {0, 4, 12, 19, 21, 11, 9, 8, 14};
    EXPECT_EQ(expected_distance, actual_distance);
}

TEST(bfs, undirected_graph2) {
//    https://www.codingame.com/playgrounds/1608/shortest-paths-with-dijkstras-algorithm/dijkstras-algorithm
    edgeList edgeList(false);
    edgeList.add_edge(0, 1, 3);
    edgeList.add_edge(0, 2, 1);
    edgeList.add_edge(1, 2, 7);
    edgeList.add_edge(2, 3, 2);
    edgeList.add_edge(1, 3, 5);
    edgeList.add_edge(1, 4, 1);
    edgeList.add_edge(3, 4, 7);

    auto actual_distance = dijkstra_shortest_distance(edgeList, 2);
    std::vector<int> expected_distance = {1, 4, 0, 2, 5};
    EXPECT_EQ(expected_distance, actual_distance);
}