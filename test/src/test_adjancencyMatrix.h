#pragma once

#include "../../src/graphs.h"
#include "gtest/gtest.h"

TEST(adjMatrix, add_remove_edge_directed) {
    adjacencyMatrix adjacencyMatrix(true);

    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            std::cout << i << ", " << j << "\t";
            auto added = adjacencyMatrix.add_edge({i, j});
//            EXPECT_EQ(added, i != j);
        }
        std::cout << "\n";
    }
    EXPECT_EQ(num_nodes, adjacencyMatrix.get_num_nodes());

//    for (int i = 0; i < num_nodes; i++) {
//        for (int j = 0; j < num_nodes; j++) {
//            auto removed = adjacencyMatrix.remove_edge({i, j});
//            EXPECT_EQ(removed, i != j);
//        }
////        std:: cout << "\n";
//        std::cout << adjacencyMatrix.get_num_nodes() << std::endl;
//        auto indegree = adjacencyMatrix.get_indegree();
//        for(int i = 0; i < num_nodes; i++) std::cout << indegree[i] << "\t"; std::cout << "\n";
//    }
////    EXPECT_EQ(0, adjacencyList.get_num_nodes());
}


TEST(adjMatrix, add_remove_edge_undirected) {
    adjacencyMatrix adjacencyMatrix(false);

    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            auto added = adjacencyMatrix.add_edge({i, j});
            EXPECT_EQ(added, i != j);
        }
    }
    EXPECT_EQ(num_nodes, adjacencyMatrix.get_num_nodes());

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            auto removed = adjacencyMatrix.remove_edge({i, j});
            EXPECT_EQ(removed, i != j);
        }
//        std:: cout << "\n";
        std::cout << adjacencyMatrix.get_num_nodes() << std::endl;
        auto indegree = adjacencyMatrix.get_indegree();
        for(int i = 0; i < num_nodes; i++) std::cout << indegree[i] << "\t"; std::cout << "\n";
    }
//    EXPECT_EQ(0, adjacencyList.get_num_nodes());
}
