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
    std::vector<std::vector<int>> adjList;
    std::vector<std::vector<int>> edges;
public:
    graph() = default;

    virtual ~graph() = default;

    virtual bool add_edge(int start, int end, int weight = 0) = 0;

    virtual bool add_edge(std::vector<int> edge) {
        return false;
    }

    virtual bool add_vertex() { return false; }

    virtual int **get_adjacentMatrix() {
        return adjMatrix;
    }

    virtual std::vector<std::vector<int>> get_adjList() {
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

    virtual void print_edges() {}



};

#endif