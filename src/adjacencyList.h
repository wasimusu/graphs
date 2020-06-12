/**
 * Implements data structure for representation of graphs as adjacency list.
 * For each vertex, we have it's list of neighbors
 * */

#pragma once
#ifndef GRAPHS_ADJACENCYLIST_H
#define GRAPHS_ADJACENCYLIST_H

#include "graph.h"
#include <algorithm>

class adjacencyList : public graph {
private:
    std::unordered_map<int, std::vector<int>> adjList;
public:
    adjacencyList() = default;

    bool add_edge(int start, int end, int weight = 0) override {
        if (std::find(adjList[start].begin(), adjList[start].end(), end) == adjList[start].end())
            return false;

        adjList[start].push_back(end);
        adjList[end].push_back(start);
        return true;
    }

    ~adjacencyList() override = default;
};

#endif //GRAPHS_ADJACENCYLIST_H
