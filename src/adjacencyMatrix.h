/**
 * @file
 * */

#pragma once
#ifndef GRAPHS_ADJACENCYMATRIX_H
#define GRAPHS_ADJACENCYMATRIX_H

#include "graph.h"
/**
 * @brief Implements data structure for representation of graphs as adjacency matrix.
 * */
class adjacencyMatrix : public graph {
private:
    int **adjMatrix = nullptr;
    int num_nodes = 0;
    const bool directed;
public:
    /**
     * @brief default constructor for adjacency matrix
     * @param [int] num_nodes the maximum number of nodes that will be in the graph
     * @param [bool] directed is the graph directed or not?
     * @returns void
     * */
    explicit adjacencyMatrix(const int num_nodes, const bool directed = true) : num_nodes(num_nodes),
                                                                                directed(directed) {
        adjMatrix = new int *[num_nodes];
        for (int i = 0; i < num_nodes; i++) {
            adjMatrix[i] = new int[num_nodes];
            std::fill(adjMatrix[i], adjMatrix[i] + num_nodes, 0);
        }
    }

    /**
     * @brief is the edge with given start and end node valid? Does it already exist?
     * @param [int] start, end: the start and end node of the edge
     * @returns [bool] true if the edge can be added to the graph because it is valid and does not already exist
     * */
    inline bool is_new_edge(const int start, const int end) {
        return (start < 0 || end < 0 || start >= num_nodes || end >= num_nodes || adjMatrix[start][end] == 0);
    }


    /**
     * @brief given start, end and optionally weight describing an edge, insert it into the graph
     * @param [int, int, int = 0] start, end, weight: parameters describing an edge(start_node, end_node, weight)
     * @returns [bool] was the edge successfully inserted into the graph
     * */
    bool add_edge(const int start, const int end, const int weight = 0) override {
        return weight == 0 ? add_edge({start, end}) : add_edge({start, end, weight});
    }

    /**
     * @brief given a reference to std::vector<int> describing an edge, insert it into the graph
     * @param [std::vector<int>&] edge: an edge description (start_node, end_node, (optionally) weight)
     * @returns [bool] was the edge successfully inserted into the graph
     * */
    bool add_edge(std::vector<int> &&edge) {
        if (edge.size() < 2 || edges.size() > 3)
            throw std::invalid_argument(
                    "2 or 3 values describe an edge. " + std::to_string(edge.size()) + " provided");

        if (edge[0] == edge[1] || !is_new_edge(edge[0], edge[1])) return false;

        if (edge.size() == 2) {
            adjMatrix[edge[0]][edge[1]] = 1;
            if (!directed) {
                adjMatrix[edge[1]][edge[0]] = 1;
            }
        } else {
            adjMatrix[edge[0]][edge[1]] = edge[2];
            if (!directed) {
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }

        return true;
    }

    bool remove_edge(const int start, const int end) override {
        if (start == end) return false;
        if (is_new_edge(start, end)) return false;

        // (end, start) edge
        if (!directed) {
            adjMatrix[end][start] = 0;
        }

        // (start, end) edge
        adjMatrix[start][end] = 0;

        return true;
    }

    bool remove_edge(const std::vector<int> &edge) override {
        return remove_edge(edge[0], edge[1]);
    }

    /**
     * @brief returns the adjacency_matrix
     * @returns [**int] adjacency_matrix
     * */
    int **get_adjacentMatrix() const {
        return adjMatrix;
    }

    /**
     * @brief returns the number of nodes in the graph
     * @returns [int] the number of nodes in the graph
     * */
    int get_num_nodes() const final {
        return num_nodes;
    }

    /**
     * @brief compute indegree for all the nodes in the graph
     * @returns [int*] indegree for all the nodes
     * */
    int *get_indegree() final {
        num_nodes = get_num_nodes();
        indegree = new int[num_nodes];
        std::fill(indegree, indegree + num_nodes, 0);
        for (int start = 0; start < num_nodes; start++) {
            for (int end = 0; end < num_nodes; end++) {
                indegree[end] += adjMatrix[start][end] != 0;
            }
        }

        return indegree;
    }

    ~adjacencyMatrix() override {
        for (int i = 0; i < num_nodes; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    };
};

#endif //GRAPHS_ADJACENCYMATRIX_H
