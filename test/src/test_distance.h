#pragma once

#include "../../src/graphs.h"
#include "gtest/gtest.h"
#include <vector>
#include <iostream>

using namespace std;

TEST(dijkstra, linear_graph) {

    edgeList edgeList(false);
    int num_nodes = 10;
    for (int i = 0; i < num_nodes - 1; i++) {
        edgeList.add_edge({i, i + 1, 1});
    }

    for (int start = 0; start < num_nodes; start++) {
        for (int end = 0; end < num_nodes; end++) {
            auto res = dijkstra_shortest_distance(edgeList, start);
            EXPECT_EQ(res[end], abs(end - start));
        }
    }
}

TEST(dijkstra, directed_graph) {
//   https://en.wikipedia.org/wiki/Shortest_path_problem
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

TEST(dijkstra, undirected_graph) {
//    https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

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

TEST(dijkstra, undirected_graph2) {
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

TEST(bellman_ford, linear_graph) {
    edgeList edgeList(true);
    int num_nodes = 5;
    for (int i = 0; i < num_nodes - 1; i++) {
        edgeList.add_edge({i, i + 1, 1});
    }
    auto res = bellman_ford(edgeList, 0);
    for (int d: res) cout << d << "\t";
    cout << '\n';
}

TEST(bellman_ford, random_graph) {
    edgeList edgeList(true);
    edgeList.add_edge({0, 1, 6});
    edgeList.add_edge({0, 2, 5});
    edgeList.add_edge({0, 3, 5});
    edgeList.add_edge({1, 4, -1});
    edgeList.add_edge({2, 1, -2});
    edgeList.add_edge({3, 2, -2});
    edgeList.add_edge({2, 4, 1});
    edgeList.add_edge({3, 5, -1});
    edgeList.add_edge({5, 6, 3});
    edgeList.add_edge({4, 6, 3});

    auto actual_distance = bellman_ford(edgeList, 0);
    vector<int> expected_distance = {0, 1, 3, 5, 0, 4, 3};
    assert(equal(actual_distance.begin(), actual_distance.end(), expected_distance.begin(), expected_distance.end()));
    EXPECT_EQ(actual_distance, expected_distance);
}

TEST(bellman_ford, random_graph2) {
    edgeList edgeList(true);
    edgeList.add_edge({2, 1, -10});
    edgeList.add_edge({3, 2, 3});
    edgeList.add_edge({0, 1, 4});
    edgeList.add_edge({0, 3, 5});

    auto actual_distance = bellman_ford(edgeList, 0);

    vector<int> expected_distance = {0, -2, 8, 5};
    assert(equal(actual_distance.begin(), actual_distance.end(), expected_distance.begin(), expected_distance.end()));
    EXPECT_EQ(actual_distance, expected_distance);
}

TEST(bellman_ford, all_pairs_graph) {
    edgeList edgeList(false);
    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            edgeList.add_edge({i, j, 1});
        }
    }

    auto res = bellman_ford(edgeList, 0);
    for (int d: res) cout << d << "\t";
    cout << '\n';
}