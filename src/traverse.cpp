#include "traverse.h"

void bfs(graph &graph, int source_node, std::vector<int> &result) {

    auto edges = graph.get_adjList();
    std::queue<int> queue;
    queue.push(source_node);

    int n = graph.get_num_nodes();
    std::vector<bool> visited(n, false);

    while (!queue.empty()) {
        auto node = queue.front();
        queue.pop();

        if (visited[node]) continue;
        visited[node] = true;

        result.push_back(node);
        for (const int child: edges[node]) {
            if (visited[child]) continue;
            queue.push(child);
        }
    }
}

void dfs(graph &graph, int source_node, std::vector<int> &result) {
    auto edges = graph.get_adjList();
    std::vector<int> stack;
    stack.push_back(source_node);

    int n = graph.get_num_nodes();
    std::vector<bool> visited(n, false);

    while (!stack.empty()) {
        auto node = stack.back();
        stack.pop_back();

        if (visited[node]) continue;
        visited[node] = true;

        result.push_back(node);
        for (const int child: edges[node]) {
            if (visited[child]) continue;
            stack.push_back(child);
        }
    }
}

void level_order_traversal(graph &graph, int source_node, std::vector<std::vector<int>> &result) {
    auto edges = graph.get_edges();
    std::vector<int> parent = {source_node};
    std::vector<int> children;

    int n = graph.get_num_nodes();
    std::vector<bool> visited(n, false);

    while (!parent.empty()) {

        for (int node: parent) {

            if (visited[node]) continue;
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
