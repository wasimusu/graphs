#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>

class graph {
protected:
    int **adjMatrix = nullptr;
    int *indegree = nullptr;
public:
    graph() = default;

    virtual ~graph() = default;

    virtual bool add_edge(int start, int end) = 0;

    virtual bool add_vertex() { return false; }

    virtual int **get_adjacentMatrix() {
        return adjMatrix;
    }

    virtual int *get_indegree() {
        return indegree;
    };
};

#endif