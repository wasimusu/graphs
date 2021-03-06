#pragma once
#ifndef GRAPHS_EDGELIST_H
#define GRAPHS_EDGELIST_H

#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>
#include "graph.h"

/**
 * @file
 * @brief Implementation of graph data structures edgeList.
 * @see base class graph for documentation
 * */
class edgeList : public graph {
private:
    std::unordered_set<int> nodes;
    std::set<std::pair<int, int>> _edges;
    std::vector<std::vector<int>> edges;
    int num_nodes = 0;
    bool directed;
    std::unordered_map<int, int> indegree_counter;

public:
    explicit edgeList(const bool directed = true) : directed(directed) {}

    inline bool is_new_edge(const int start, const int end) {
        return _edges.count({start, end}) != 1;
    }

    /*
     * @brief add edge in the graph. Does nothing if the edge already exists
     * An edge is described by start_node (start), end_node (end) and optionally by weight.
     * **/
    bool add_edge(const int start, const int end, const int weight = 0) final {
        return add_edge({start, end, weight});
    }

    /**
     * @brief add edge in the graph. Does nothing if the edge already exists
     * It is the core function used by every other method that adds edges into the graph.
     *
     * @returns[bool] true if the edges were successfully added to the graph, false otherwise.
     * If the edge was already present in the graph, it returns false
     */
    bool add_edge(std::vector<int> edge) override {
        if (edge[0] == edge[1]) return false;
        if (edge.size() != 2 && edge.size() != 3)
            throw std::invalid_argument(
                    "2 or 3 values describe an edge. " + std::to_string(edge.size()) + " provided");

        if (_edges.count({edge[0], edge[1]})) {
            return false;
        }

        if (edge.size() == 2) { edge.push_back(1); }

        if (!directed) {
            auto other_edge{edge};
            std::swap(other_edge[0], other_edge[1]);

            nodes.insert(other_edge[0]);
            nodes.insert(other_edge[1]);
            edges.push_back(std::move(other_edge));

            _edges.insert({edge[1], edge[0]});
            ++indegree_counter[edge[0]];
        }

        nodes.insert(edge[0]);
        nodes.insert(edge[1]);
        ++indegree_counter[edge[1]];
        _edges.insert({edge[0], edge[1]});
        edges.push_back(std::move(edge));

        return true;
    }

    template<class... Args>
    bool add_edges(std::vector<int> edge, Args... edges) {
        return add_edge(std::move(edge)) + add_edges(edges...);
    }

    bool remove_edge(const int start, const int end) override {
        if (start == end || is_new_edge(start, end)) return false;

        const int num_edges = edges.size();
        int target = (directed ? 1 : 2);

        int id = 0;
        for (int i = 0; i < num_edges; i++) {
            if (!directed && edges[id][1] == start && edges[id][0] == end) {
                --indegree_counter[start];
                edges.erase(edges.begin() + id);
                _edges.erase({end, start});
                if (--target == 0) break;
                continue;
            }

            if (edges[id][0] == start && edges[id][1] == end) {
                --indegree_counter[end];
                edges.erase(edges.begin() + id);
                _edges.erase({start, end});
                if (--target == 0) break;
                continue;
            }

            ++id;
        }

        if (indegree_counter[start] == 0) nodes.erase(start);
        if (indegree_counter[end] == 0) nodes.erase(end);
        return true;
    }

    bool remove_edge(const std::vector<int> &edge) override {
        return remove_edge(edge[0], edge[1]);
    }


    /**
     * @brief computes and returns adjacency matrix of the graph
     * */
    int **get_adjacentMatrix() override {
        num_nodes = get_num_nodes();
        adjMatrix = new int *[num_nodes];
        for (int i = 0; i < num_nodes; i++) {
            adjMatrix[i] = new int[num_nodes];
            std::fill(adjMatrix[i], adjMatrix[i] + num_nodes, 0);
        }

        if (edges[0].size() == 2) {
            for (const auto &edge: edges) {
                adjMatrix[edge[0]][edge[1]] = 1;
            }
        }

        if (edges[0].size() == 3) {
            for (const auto &edge: edges) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
            }
        }

        return adjMatrix;
    }

    /**
     * @brief computes and returns the adjacent list representing the graph
     */
    std::unordered_map<int, std::vector<int>> get_adjacentList() final {
        for (const auto &edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
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

#endif //GRAPHS_EDGELIST_H