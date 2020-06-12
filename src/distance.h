/**
 * @brief Implements algorithms to compute distance between nodes in a graph
 * */

#pragma once
#ifndef GRAPHS_DISTANCE_H
#define GRAPHS_DISTANCE_H


/*
 * @brief Implements dijsktra's shortest path algorithm to find the shortest distance between source_node and all
 * other nodes in the graph.
 * Assumes the nodes are enumerated in 0 base.
 *
 * @param[int] source_node, target_node: the two nodes for which shortest connecting path is to be computed
 * @returns[int]: shortest path connecting two input nodes
 * **/
int dijkstra_shortest_distance(graph &graph, int source_node, int target_node);


/*
 * @brief: Computes all pair shortest path using floyd's all path shortest path algorithm.
 * As long as there is no cycle, this algorithm works fine.
 * reference: https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 *
 * @param[graph] graph: input graph
 * @returns[int**] distances: 2D array containing distance between each pair of nodes
 * **/
int **all_pair_shortest_path(graph &graph);


/**
 * @brief Implements Bellman Ford algorithm to find shortest distances when the edges are negative
 * Note: Does not work when the total weight of the cycle is negative
 *
 * @param[int]source_node: The source node from which shortest distance is to be computed
 * @param[graph]graph: Input graph on which shortest distance is to be computed
 * @returns[std::vector<int>] distances: shortest distance from source_node to all other nodes
 * @throws: std::invalid_argument error if the graph is not weighted.
 **/
std::vector<int> bellman_ford(graph &graph, const int source_node);


#endif //GRAPHS_DISTANCE_H