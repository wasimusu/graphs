/**
 * @brief Implements algorithms to compute distance between nodes in a graph
 * */

#pragma once
#ifndef GRAPHS_DISTANCE_H
#define GRAPHS_DISTANCE_H


/*
 * @brief Implements dijsktra's shortest path algorithm to find the shortest distance between source_node and all
 * other nodes in the graph.
 *
 * @param[graph] graph: input graph of any type: edgeList, adjacencyList, adjacencyMatrix
 * @param[int] source_node: the nodes for which shortest path to all other nodes is to be computed
 * @returns[vector<int>]: shortest path between source_node and all other nodes
 * **/
std::vector<int> dijkstra_shortest_distance(graph &graph, int source_node);


/*
 * @brief: Computes all pair shortest path using floyd's all path shortest path algorithm.
 * As long as there is no cycle, this algorithm works fine.
 * reference: https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 *
 * @param[graph] graph: input graph of any type: edgeList, adjacencyList, adjacencyMatrix
 * @returns[int**] distances: 2D array containing distance between each pair of nodes
 * **/
int **all_pair_shortest_path(graph &graph);


/**
 * @brief Implements Bellman Ford algorithm to find shortest distances when the edges are negative
 * Note: Does not work when the total weight of the cycle is negative
 *
 * @param[graph] graph: input graph of any type: edgeList, adjacencyList, adjacencyMatrix
 * @param[int]source_node: The source node from which shortest distance is to be computed
 * @returns[std::vector<int>] distances: shortest distance from source_node to all other nodes
 *
 * @throws: std::invalid_argument error if the graph is not weighted.
 **/
std::vector<int> bellman_ford(graph &graph, const int source_node);


#endif //GRAPHS_DISTANCE_H