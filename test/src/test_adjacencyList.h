#pragma once

#include "../../src/graphs.h"
#include "gtest/gtest.h"

TEST(adjList, add_remove_edge_directed) {
    adjacencyList adjacencyList(true);

    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            auto added = adjacencyList.add_edge({i, j});
            EXPECT_EQ(added, i != j);
        }
    }
    EXPECT_EQ(num_nodes, adjacencyList.get_num_nodes());

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            auto removed = adjacencyList.remove_edge({i, j});
            EXPECT_EQ(removed, i != j);
        }
//        std:: cout << "\n";
        std::cout << adjacencyList.get_num_nodes() << std::endl;
        auto indegree = adjacencyList.get_indegree();
        for(int i = 0; i < num_nodes; i++) std::cout << indegree[i] << "\t"; std::cout << "\n";
    }
//    EXPECT_EQ(0, adjacencyList.get_num_nodes());
}

TEST(adjList, add_remove_edge_undirected) {
    adjacencyList adjacencyList(false);

    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            auto added = adjacencyList.add_edge({i, j});
            EXPECT_EQ(added, true);
        }
    }
    EXPECT_EQ(num_nodes, adjacencyList.get_num_nodes());

    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            auto removed = adjacencyList.remove_edge({i, j});
            EXPECT_EQ(removed, true);
        }
    }
    EXPECT_EQ(0, adjacencyList.get_num_nodes());
}