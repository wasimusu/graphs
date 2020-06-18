/**
 * @file
 * @brief traverse.h implements traversal methods for graphs.
 * It does not implement inorder, preorder and postorder traversal because
 * they make sense only for binary trees and binary search trees
 * */

#pragma once
#ifndef GRAPHS_TRAVERSE_H
#define GRAPHS_TRAVERSE_H

#include <queue>
#include <vector>

/**
 * @brief Implements iterative algorithm for breadth first search traversal on a graph.
 * For undirected graphs we have keep track of visited nodes.
 *
 * @param[in] graph: input graph on which breadth first search traversal has to be performed.
 * @param[in] source_node: the node from which to start the traversal
 * @param[out]result: the nodes of the graph in bfs order
 *
 * */
void bfs(graph &graph, int source_node, std::vector<int> &result);


/**
 * @brief Implements iterative algorithm for depth first search traversal on a graph.
 * Keep track of the visited nodes in graphs. It's not required to keep track of visited nodes in directed graphs
 *
 * @param[in] graph: input graph on which depth first search traversal has to be performed.
 * @param[in] source_node: the node from which to start the traversal
 * @param[out]result: the nodes of the graph in dfs order
 * */
void dfs(graph &graph, int source_node, std::vector<int> &result);


/**
 * @brief Implements iterative algorithm for level order search for a graph.
 *
 * @param[in] graph: input graph on which level order traversal has to be performed.
 * @param[in] source_node: the node from which to start the traversal
 * @param[out]result: the nodes of the graph in level order
 * */
void level_order_traversal(graph &graph, int source_node, std::vector<std::vector<int>> &result);


#endif //GRAPHS_TRAVERSE_H
