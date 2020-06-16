#pragma once
#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <ostream>

class graph {
protected:
    int **adjMatrix = nullptr;
    int *indegree = nullptr;
    std::unordered_map<int, std::vector<int>> adjList;
    std::vector<std::vector<int>> edges;
public:
    graph() = default;

    virtual ~graph() = default;

    virtual bool add_edge(int start, int end, int weight = 0) = 0;

    virtual bool add_edge(std::vector<int> edge) {
        return false;
    }

    virtual bool remove_edge(const int start, const int end) {
        return false;
    }

    virtual bool remove_edge(const std::vector<int> &edge) {
        return false;
    }

    virtual int **get_adjacentMatrix() {
        return adjMatrix;
    }

    virtual std::unordered_map<int, std::vector<int>> get_adjList() {
        return adjList;
    }

    virtual std::vector<std::vector<int>> get_edges() {
        return edges;
    }

    virtual int *get_indegree() {
        return indegree;
    };

    virtual int get_num_nodes() const {
        return 0;
    }

};

#endif