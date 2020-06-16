/**
 * Implements data structure for representation of graphs as adjacency list.
 * For each vertex, we have it's list of neighbors.
 * Currently the edges represented by adjacencyList is only unweighted edges.
 * */

#pragma once
#ifndef GRAPHS_ADJACENCYLIST_H
#define GRAPHS_ADJACENCYLIST_H

#include "graph.h"
#include <algorithm>

class adjacencyList : public graph {
private:
    std::unordered_set<int> nodes;
    const bool directed;
    int num_nodes = 0;
    std::unordered_map<int, int> indegree_counter;

public:
    explicit adjacencyList(bool directed = true) : directed(directed) {};

    inline bool is_new_edge(const int start, const int end) {
        return (!(adjList.count(start) &&
                  std::find(adjList[start].begin(), adjList[start].end(), end) != adjList[start].end()));
    }

    bool add_edge(const int start, const int end, const int weight = 0) override {
        if (start == end || !is_new_edge(start, end)) return false;

        if (!directed) {
            adjList[end].push_back(start);
            ++indegree_counter[start];
        }

        adjList[start].push_back(end);
        nodes.insert(end);
        nodes.insert(start);
        ++indegree_counter[end];
        return true;
    }

    bool add_edge(std::vector<int> edge) {
        return add_edge(edge[0], edge[1]);
    }

    bool remove_edge(const int start, const int end) override {
        if (start == end || is_new_edge(start, end)) return false;

        // (end, start) edge
        if (!directed) {
            --indegree_counter[start];
            if (indegree_counter[start] == 0) {
                adjList.erase(end);
            } else {
                adjList[end].erase(find(adjList[end].begin(), adjList[end].end(), start));
            }
        }

        // (start, end) edge
        --indegree_counter[end];
        if (indegree_counter[end] == 0) {
            adjList.erase(start);
        } else {
            adjList[start].erase(find(adjList[start].begin(), adjList[start].end(), end));
        }


        if (indegree_counter[start] == 0 || indegree_counter[end] == 0) {
            if (indegree_counter[start] == 0) { nodes.erase(start); }
            if (indegree_counter[end] == 0) { nodes.erase(end); }
            std::cout << "Number of nodes : " << nodes.size() << std::endl;
        }

        return true;
    }

    bool remove_edge(const std::vector<int> &edge) override {
        return remove_edge(edge[0], edge[1]);
    }

    int **get_adjacentMatrix() override {
        num_nodes = get_num_nodes();
        adjMatrix = new int *[num_nodes];
        for (int i = 0; i < num_nodes; i++) {
            adjMatrix[i] = new int[num_nodes];
        }
        std::fill(*adjMatrix, *adjMatrix + num_nodes * num_nodes, 0);

        for (const auto&[parent, children]: adjList) {
            for (const auto &child: children) {
                adjMatrix[parent][child] = 1;
            }
        }

        return adjMatrix;
    }


    std::vector<std::vector<int>> get_edges() override {
        std::vector<std::vector<int>> edges;
        for (const auto&[parent, children]: adjList) {
            for (const auto &child: children) {
                edges.push_back({parent, child});
            }
        }
        return edges;
    }

    int *get_indegree() override {
        if (indegree) delete[] indegree;
        num_nodes = get_num_nodes();
        indegree = new int[num_nodes];
        std::fill(indegree, indegree + num_nodes, 0);
        for (const auto&[parent, children]: adjList) {
            for (const auto &child: children) {
                ++indegree[child];
            }
        }

        return indegree;
    };

    int get_num_nodes() const override {
        return nodes.size();
    }

    ~adjacencyList() override = default;
};

#endif //GRAPHS_ADJACENCYLIST_H
