#pragma once

#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include "graph.h"

class edgeList : public graph {
private:
    std::unordered_set<int> nodes;
    std::set<std::pair<int, int>> _edges;
    std::vector<std::vector<int>> edges;
    int num_nodes = 0;
    bool directed;

public:
    explicit edgeList(const bool directed = false) : directed(directed) {}

    /*
     * @brief: add edge in the graph. Does nothing if the edge already exists
     * **/
    bool add_edge(int start, int end, int weight = 0) final {
        return add_edge({start, end, weight});
    }

    /**
     * @brief: add edge in the graph. Does nothing if the edge already exists
     * It is the core function used by every other method that adds edges into the graph.
     *
     * @returns true if the edges were successfully added to the graph, false otherwise.
     * If the edge was already present in the graph, it returns false
     */
    bool add_edge(std::vector<int> edge) {
        if (edge.size() < 2)
            throw std::invalid_argument(
                    "Two or three values describe an edge. " + std::to_string(edge.size()) + " provided");

        if (_edges.count({edge[0], edge[1]})) {
            return false;
        }

        if (edge.size() == 2) edge.push_back(0);

        if (!directed) {
            auto other_edge{edge};
            std::swap(other_edge[0], other_edge[1]);

            nodes.insert(other_edge[0]);
            nodes.insert(other_edge[1]);
            edges.push_back(std::move(other_edge));
        }

        nodes.insert(edge[0]);
        nodes.insert(edge[1]);
        edges.push_back(std::move(edge));

        return true;
    }

    template<class... Args>
    bool add_edges(std::vector<int> edge, Args... edges) {
        return add_edge(std::move(edge)) + add_edges(edges...);
    }

    /**
     * @brief computes and returns adjacency matrix of the graph
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

        return adjMatrix;
    }

    /**
     * @brief computes and returns the adjacent list representing the graph
     */
    std::vector<std::vector<int>> get_adjList() final {
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

    /**
     * @brief returns edges representing the graph. O(1) - no computation required.
     * */
    std::vector<std::vector<int>> get_edges() final {
        return edges;
    }

    /**
     * @brief computes and returns the indegree of all the nodes in the graph
     * */
    int *get_indegree() final {
        if (indegree) return indegree;
        num_nodes = get_num_nodes();
        indegree = new int[num_nodes];
        std::fill(indegree, indegree + num_nodes, 0);
        for (const auto &edge: edges) {
            ++indegree[edge[1]];
        }
        return indegree;
    }

    /**
     * @brief returns the total number of nodes/vertex in the graph
     * */
    int get_num_nodes() const final { return nodes.size(); }

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

    ~edgeList() override = default;
};