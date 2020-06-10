#pragma once

#include <set>
#include <unordered_set>
#include <vector>
#include "graph.h"

class edgeList : public graph {
private:
    std::unordered_set<int> nodes;
    std::set<std::pair<int, int>> _edges;
    std::vector<std::vector<int>> edges;
    int num_nodes = 0;
    bool directed;

public:
    edgeList(const bool directed = false) : directed(directed) {}

    bool add_edge(int start, int end, int weight = 0) final {
        return _add_edge({start, end, weight});
    }

    bool _add_edge(std::vector<int> edge) {
        if (_edges.count({edge[0], edge[1]})) {
            return false;
        }

        if (edge.size() == 2) edge.push_back(0);

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

    /**
     * Assumes the indices are 0 based.
     * The behavior is undefined otherwise
     * */
    int **get_adjacentMatrix() final {
        if (adjMatrix) return adjMatrix;

        num_nodes = get_num_nodes();
        adjMatrix = new int *[num_nodes];
        for (int i = 0; i < num_nodes; i++) {
            adjMatrix[i] = new int[num_nodes];
            std::fill(adjMatrix[i], adjMatrix[i] + num_nodes, 0);
        }

        if (!directed) {
            for (const auto &edge: edges) {
                adjMatrix[edge[0]][edge[1]] = 1;
            }
        }

        if (directed) {
            for (const auto &edge: edges) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
            }
        }

        for(int i = 0; i < num_nodes; i++){
            for(int j = 0; j < num_nodes; j++) std::cout << adjMatrix[i][j] << " "; std::cout << "\n";
        }

        return adjMatrix;
    }

    virtual std::vector<std::vector<int>> get_adjList() final {
        for (int i = 0; i < get_num_nodes(); i++) adjList.push_back({});

        for (const auto edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
        }

        for (const auto list: adjList) {
            for (const auto node: list) std::cout << node << " ";
            std::cout << '\n';
        }

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

    friend std::ostream &operator<<(std::ostream &os, const std::vector<int> &array) {
        for (const int num: array) {
            os << num << '\t';
        }
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<int>> &edges) {
        for (const auto &edge: edges) {
            os << edge[0] << ", " << edge[1] << ", " << edge[2] << '\n';
        }
        return os;
    }

    ~edgeList() = default;
};