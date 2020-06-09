#pragma once

#include <set>
#include <unordered_set>
#include <vector>
#include "graph.h"

class edgeList : public graph {
private:
    std::unordered_set<int> start_nodes, end_nodes, nodes;
    std::vector<std::vector<int>> edges;
    int num_nodes = 0;
    bool directed = true;

public:
    edgeList() = default;

    bool add_edge(int start, int end, int weight = 0) final {
        return _add_edge({start, end, weight});
    }

    bool _add_edge(std::vector<int> edge) {
        if (start_nodes.count(edge[0]) && end_nodes.count(edge[1])) {
            return false;
        }

        if (edge.size() == 2) edge.push_back(0);

        start_nodes.insert(edge[0]);
        end_nodes.insert(edge[1]);
        nodes.insert(edge[0]);
        nodes.insert(edge[1]);
        edges.push_back(std::move(edge));
        return true;
    }

    template<class... Args>
    bool add_edge(Args... edges) {
        return (_add_edge(edges) + ...);
    }

    bool add_edge(std::vector<int> edge) {
        return _add_edge(edge);
    }

    int **get_adjacentMatrix() final {
        if (adjMatrix) return adjMatrix;

        num_nodes = get_num_nodes();
        adjMatrix = new int *[num_nodes];
        for (int i = 0; i < num_nodes; i++) {
            adjMatrix[i] = new int[num_nodes];
            std::fill(adjMatrix[i], adjMatrix[i] + num_nodes, 0);
        }

        if (directed) {
            for (const auto &edge: edges) {
                adjMatrix[edge[0]][edge[1]] = 1;
            }
        }

        if (!directed) {
            for (const auto &edge: edges) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
            }
        }

        return adjMatrix;
    }

    virtual std::vector<std::vector<int>> get_adjList() final {
        return adjList;
    }

    virtual std::vector<std::vector<int>> get_edges() {
        return edges;
    }

    int *get_indegree() {
        if (indegree) return indegree;
        num_nodes = get_num_nodes();
        indegree = new int[num_nodes];
        std::fill(indegree, indegree + num_nodes, 0);
        for (const auto &edge: edges) {
            ++indegree[edge[1]];
        }
        return indegree;
    }

    int get_num_nodes() const { return nodes.size(); }

    void print_edges() {
        int n = get_num_nodes();
        std::cout << "Total nodes : " << n << "\n";
        for (int i = 0; i < edges.size(); i++) {
            std::cout << edges[i][0] << ", " << edges[i][1] << ", " << edges[i][2] << "\n";
        }
    }


    ~edgeList() = default;
};