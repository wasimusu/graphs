#pragma once

#include "graph.h"

class adjacencyList : public graph {
private:
    std::unordered_map<int, std::vector<int>> adjList;
public:
    adjacencyList() = default;

    bool add_edge(int start, int end, int weight = 0) override {
        if (find(adjList[start].begin(), adjList[start].end(), end) == adjList[start].end())
            return false;

        adjList[start].push_back(end);
        adjList[end].push_back(start);
        return true;
    }

    ~adjacencyList() override = default;
};