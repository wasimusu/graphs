#pragma once

#include <set>
#include "graph.h"

class edgeList : public graph {
private:
    std::set<std::pair<int, int>> edges;
    int num_nodes = 0;

public:
    edgeList() = default;

    bool add_edge(int start, int end) override {
        if (edges.count({start, end}) == 1) return false;
        num_nodes = std::max(num_nodes, std::max(start, end) + 1);
        edges.insert({start, end});
        return true;
    }

    int **get_adjacentMatrix() override {
        if (adjMatrix) return adjMatrix;
        adjMatrix = new int *[num_nodes];
        for (int i = 0; i < num_nodes; i++) {
            adjMatrix[i] = new int[num_nodes];
            std::fill(adjMatrix[i], adjMatrix[i] + num_nodes, 0);
        }

        for(const auto& [start, end]: edges){
            adjMatrix[start][end] = 1;
        }

        return adjMatrix;
    }

    int *get_indegree() override {
        if (indegree) return indegree;
        indegree = new int[num_nodes];
        std::fill(indegree, indegree + num_nodes, 0);
        for (const auto&[_, end]: edges) {
            ++indegree[end];
        }
        return indegree;
    }

    ~edgeList() override = default;
};