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
 * For undirected graphs we have keep track of visited nodes.
 *
 * */
void bfs(graph &graph, int source_node, std::vector<int> &result) {

    auto edges = graph.get_adjList();
    std::queue<int> queue;
    queue.push(source_node);

    int n = graph.get_num_nodes();
    std::vector<bool> visited(n, false);

    while (!queue.empty()) {
        auto node = queue.front();
        queue.pop();

        if(visited[node]) continue;
        visited[node] = true;

        result.push_back(node);
        for (const int child: edges[node]) {
            if (visited[child]) continue;
            queue.push(child);
        }
    }
}

/**
 * @brief Implements iterative algorithm for depth first search for a graph.
 * Keep track of the visited nodes in graphs. It's not required to keep track of visited nodes in directed graphs
 *
 * */
void dfs(graph &graph, int source_node, std::vector<int> &result) {
    auto edges = graph.get_adjList();
    std::vector<int> stack;
    stack.push_back(source_node);

    int n = graph.get_num_nodes();
    std::vector<bool> visited(n, false);

    while (!stack.empty()) {
        auto node = stack.back();
        stack.pop_back();

        if(visited[node]) continue;
        visited[node] = true;

        result.push_back(node);
        for (const int child: edges[node]) {
            if (visited[child]) continue;
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

    int n = graph.get_num_nodes();
    std::vector<bool> visited(n, false);

    while (!parent.empty()) {

        for (int node: parent) {

            if(visited[node]) continue;
            visited[node] = true;

            for (int child: edges[node]) {
                if (visited[child]) continue;
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
