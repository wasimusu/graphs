/**
 * @file
 * @brief Implements algorithms pertaining to connectivity in a graph
 * */


#pragma once
#ifndef GRAPHS_CONNECTIVITY_H
#define GRAPHS_CONNECTIVITY_H

/**
 * @brief checks if two input nodes are connected in the input graph or not
 * @param [int] source_node, target_node: nodes in the graph for which connectivity is to be determined
 * @param [graph] graph: input graph
 * @returns[bool] whether the two nodes are connected or not
 * */
constexpr bool is_connected(graph &graph, const int source_node, const int target_node);

/**
 * @brief computes the lowest common ancestor (lca) of two nodes in a graph
 * @param [int] node1, node2: nodes in the graph for which lca is to be computed
 * @param [graph] graph: input graph
 * @returns[int] the lowest common ancestor of the two nodes
 * */
constexpr int lowest_common_ancestor(graph &graph, const int node1, const int node2);

/**
 * @brief computes the number of connected components in the graph
 * @returns[size_t] the number of connected components in the graph
 * */
constexpr size_t num_connected_components(graph &graph);

/**
 * @brief determines if the graph contains a cycle or not.
 * */
constexpr size_t contains_cycle(graph &graph);


#endif //GRAPHS_CONNECTIVITY_H
