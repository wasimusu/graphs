/**
 * @file
 * */
#pragma once
#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <ostream>

/**
 * @brief Base class of all other graph data structures: edgeList, adjacencyMatrix, adjacencyList.
 * This is a pure abstract class and is not instantiatable. However, it can be used to point derived classes.
 *
 * Note: No self loop is allowed and the nodes are enumerated using 0 base. Users not using
 * 0 base for enumeration might experience undefined behavior.
 *
 * Also, all the data structures have same interface which makes it easy to switch the underlying data structures
 * All algorithms have data structure agnostic implementation. You can pass into them any type of graph
 * */
class graph {
protected:
    int **adjMatrix = nullptr;
    int *indegree = nullptr;
    std::unordered_map<int, std::vector<int>> adjList;
    std::vector<std::vector<int>> edges;
public:
    graph() = default;

    virtual ~graph() = default;

    /*
     * @brief adds edge in the graph. Does nothing if the edge already exists.
     * An edge is described by start_node (start), end_node (end) and optionally by weight.
     *
     * @returns [bool] whether the edge was successfully inserted or not.
     * An edge can not be inserted for two reasons:
     * - It already exists
     * - It is invalid. For instance, in ajdacencyMatrix your node id should be less (0 base)
     * than number of nodes the graph is instantiated with.
     **/
    virtual bool add_edge(int start, int end, int weight = 0) = 0;

    /**
     * @brief add edge in the graph. Does nothing if the edge already exists.
     *
     * @returns [bool] true if the edges were successfully added to the graph, false otherwise.
     * If the edge was already present in the graph, it returns false
     *
     * @throws invalid_argument exception if the size of the edge is not 2 or 3.
     */
    virtual bool add_edge(std::vector<int> edge) {
        return false;
    }

    /*
     * @brief removes edge from the graph. Does nothing if the edge does not exist.
     * An edge for removal is completely described by start_node (start) and end_node (end)
     *
     * @returns [bool] whether the edge was successfully removed or not.
     * An edge can not be removed if it does not already exist
     **/
    virtual bool remove_edge(const int start, const int end) {
        return false;
    }

    /**
     * @see remove_edge(const int start, const int end)
     * */
    virtual bool remove_edge(const std::vector<int> &edge) {
        return false;
    }

    /**
     * @brief computes adjacency Matrix of the graph.
     * Note: Computation is not required if the data structure is adjacencyMatrix
     *
     * @returns [int**] adjacencyMatrix of a graph which is a pointer to 2D int array
     * */
    virtual int **get_adjacentMatrix() {
        return adjMatrix;
    }

    /**
     * @brief computes adjacent list of the graph.
     * Note: Computation is not required if the data structure is adjacencyList
     *
     * @returns [std::unordered_map<int, std::vector<int>>] adjacencyMatrix of a graph which is a pointer to 2D int array
     * */
    virtual std::unordered_map<int, std::vector<int>> get_adjacentList() {
        return adjList;
    }

    /**
     * @brief computes edge list of the graph.
     * Note: Computation is not required if the data structure is edgeList
     *
     * @returns [std::vector<std::vector<int>>] adjacencyMatrix of a graph which is a pointer to 2D int array
     * */
    virtual std::vector<std::vector<int>> get_edges() {
        return edges;
    }

    /**
     * @brief computes indegree of the nodes in the graph.
     *
     * @returns [int*] pointer to 1D int array of size the number of nodes in the graph
     * */
    virtual int *get_indegree() {
        return indegree;
    };

    /**
     * @brief returns the number of nodes in the graph
     * @returns [int*] pointer to 1D int array of size the number of nodes in the graph
     * */
    virtual int get_num_nodes() const {
        return 0;
    }

};

#endif