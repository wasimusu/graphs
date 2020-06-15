#pragma once

#include "../../src/graphs.h"
#include "gtest/gtest.h"

TEST(edges, add_edge_directed1) {
    edgeList edgeList;

    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            auto added = edgeList.add_edge({i, j});
            EXPECT_EQ(added, true);
        }
    }

    EXPECT_EQ(num_nodes, edgeList.get_num_nodes());
}

TEST(edges, add_edge_variadic) {
    edgeList edges;
}

TEST(edges, add_edge_directed2) {
    edgeList edgeList;

    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            auto added = edgeList.add_edge(i, j);
            EXPECT_EQ(added, true);
        }
    }

    EXPECT_EQ(num_nodes, edgeList.get_num_nodes());
}


TEST(edges, cant_add_edge) {
    edgeList edgeList;
    EXPECT_THROW(edgeList.add_edge({1}), std::invalid_argument);
}

TEST(edges, add_edge_undirected) {
    edgeList edgeList;


}

TEST(edges, remove_edge) {

}

class edgeListTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        edgeList.add_edge(0, 1, 4);
        edgeList.add_edge(0, 2, 2);
        edgeList.add_edge(1, 2, 5);
        edgeList.add_edge(1, 3, 10);
        edgeList.add_edge(2, 4, 3);
        edgeList.add_edge(4, 3, 4);
        edgeList.add_edge(3, 5, 11);
    }

    edgeList edgeList;
};

TEST_F(edgeListTest, indegree_undirected) {
    auto actual_indegree = edgeList.get_indegree();
    int expected_indegree[6] = {2, 3, 3, 3, 2, 1};
    EXPECT_EQ(actual_indegree, expected_indegree);
}

TEST(indegree, directed1) {

    edgeList edgeList(false);
    int num_nodes = 10;
    for (int i = 0; i < num_nodes - 1; i++) {
        edgeList.add_edge({i, i + 1});
    }

    // Reference indegree
    int indegree[num_nodes];
    std::fill(indegree, indegree + num_nodes, 2);
    indegree[0] = 1;
    indegree[num_nodes - 1] = 1;

    auto expected_indegree = edgeList.get_indegree();
    bool res = std::equal(indegree, indegree + num_nodes, expected_indegree);
    EXPECT_EQ(res, true);
    delete[] expected_indegree;
}

TEST(indegree, directed2) {
    edgeList edgeList(true);

    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            auto added = edgeList.add_edge({i, j});
            EXPECT_EQ(added, true);
        }
    }

    // Reference indegree
    int indegree[num_nodes];
    std::fill(indegree, indegree + num_nodes, num_nodes);

    auto actual_indegree = edgeList.get_indegree();
    bool res = std::equal(indegree, indegree + num_nodes, actual_indegree);
    EXPECT_EQ(res, true);
    delete[] actual_indegree;
}


TEST(indegree, undirected) {

}

TEST(adjMatrix, directed) {
    edgeList edgeList;

    int num_nodes = 10;
    int adjMatrix[num_nodes][num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            auto added = edgeList.add_edge({i, j});
            adjMatrix[i][j] = 1;
            EXPECT_EQ(added, true);
        }
    }

    EXPECT_EQ(num_nodes, edgeList.get_num_nodes());

    auto actual_adjMatrix = edgeList.get_adjacentMatrix();
    for (int r = 0; r < num_nodes; r++) {
        for (int c = 0; c < num_nodes; c++) {
            EXPECT_EQ(actual_adjMatrix[r][c], adjMatrix[r][c]);
            EXPECT_EQ(actual_adjMatrix[r][c], 1);
        }
    }
}


TEST(adjMatrix, undirected) {

}
