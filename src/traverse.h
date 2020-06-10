#ifndef GRAPHS_TRAVERSE_H
#define GRAPHS_TRAVERSE_H

#include <queue>
#include <vector>

/**
 * traverse.h implements traversal methods for graphs.
 * It does not implement inorder, preorder and postorder traversal because
 * they make sense only for binary trees and binary search trees
 * */


/**
 * @brief Implements iterative algorithm for breadth first search for a graph.
 *
 * */
void bfs(graph &graph, int source_node, std::vector<int> &result) {

    auto edges = graph.get_adjList();
    std::queue<int> queue;
    queue.push(source_node);

    while (!queue.empty()) {
        auto node = queue.front();
        queue.pop();
        result.push_back(node);
        for (const int child: edges[node]) {
            queue.push(child);
        }
    }
}

/**
 * @brief Implements iterative algorithm for depth first search for a graph.
 *
 * */
void dfs(graph &graph, int source_node, std::vector<int> &result) {
    auto edges = graph.get_adjList();
    std::vector<int> stack;
    stack.push_back(source_node);

    while (!stack.empty()) {
        auto node = stack.back();
        stack.pop_back();
        result.push_back(node);
        for (const int child: edges[node]) {
            stack.push_back(child);
        }
    }
}

/**
 * @brief Implements iterative algorithm for level order search for a graph.
 *
 * */
void level_order_traversal(graph &graph, int source_node, std::vector<std::vector<int>> &result) {
    auto edges = graph.get_edges();
    std::vector<int> parent = {source_node};
    std::vector<int> children;

    while (!parent.empty()) {

        for (int node: parent) {
            for (int child: edges[node]) {
                children.push_back(child);
            }
        }

        if (children.empty())
            return;

        result.push_back(children);
        std::swap(parent, children);
        children.clear();
    }
}


#endif //GRAPHS_TRAVERSE_H
