#ifndef GRAPHS_ALGORITHM_H
#define GRAPHS_ALGORITHM_H

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <numeric>

void bfs(graph &graph, int start, std::vector<int> result);

void dfs(graph &graph, int start, std::vector<int> result);

void topological_sort(int num_nodes, graph *graph, std::vector<int> &result) {

    auto adjacent = graph->get_adjacentMatrix();
    int *indegree = graph->get_indegree();

    std::deque<int> source;
    for (int node = 0; node < num_nodes; node++) {
        if (indegree[node] == 0) {
            source.push_back(node);
        }
    }

    while (!source.empty()) {
        const auto node = source.front();
        source.pop_front();
        result.push_back(node);

        auto prereq = adjacent[node];
        for (int i = 0; i < num_nodes; i++) {
            int child = prereq[i];
            if (child == 0) continue;
            indegree[i] -= 1;
            if (indegree[i] == 0) {
                source.push_back(i);
            }
        }
    }

    reverse(result.begin(), result.end());
}

/**
 * Requires weighted edge list
 * @return pair[int, vector<vector<int>>]: returns pair of total minimum cost and the nodes that will span the tree
 * */
int mst_prim(graph *graph, int source_node = -1) {
    // Let's assume that there is no starting point

    // Comparator for a min-heap
    auto compare = [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[2] > b[2];
    };

    auto edge_list = graph->get_edges();
    std::make_heap(edge_list.begin(), edge_list.end(), compare);

    int min_cost = 0;
    std::unordered_set<int> visited;

    int n = edge_list.size();
    for (int i = 0; i < n; i++) {
        int start_node = edge_list[0][0], end_node = edge_list[0][1], cost = edge_list[0][2];

        std::pop_heap(edge_list.begin(), edge_list.end(), compare);
        edge_list.pop_back();

        if (visited.count(start_node) && visited.count(end_node)) continue;

        visited.insert(start_node);
        visited.insert(end_node);
        min_cost += cost;
    }

    return min_cost;
}

/**
 * Requires weighted edge list
 * */
void kruskal_prim(graph *graph, std::vector<int> &result, int start_node = -1) {}

int dijkstra_shortest_distance(graph *graph, int source_node, int target_node) {

    auto adjacent = graph->get_adjacentMatrix();
    int n = graph->get_num_nodes();
    int distances[n];
    std::fill(distances, distances + n + 1, std::numeric_limits<int>::max());
    distances[source_node] = 0;
    std::vector<bool> visited(n, false);

    // priority queue of distance
    std::vector<std::pair<int, int>> pq = {{source_node, 0}};

    auto compare_min = [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second > b.second;
    };

    // Go through each promising node and relax weights
    while (!pq.empty()) {
        auto [node, cost] = pq[0];
        std::pop_heap(pq.begin(), pq.end(), compare_min);
        pq.pop_back();

        if (visited[node]) continue;
        visited[node] = true;

        auto adj_list = adjacent[node];
        std::cout << node << "\t";
        for (int child = 0; child < n; child++) {
            int weight = adj_list[child];
            std::cout << child << "\t";
            if (weight == 0) continue;
            if (visited[child]) continue;
            distances[child] = std::min(distances[child], adjacent[node][child] + cost);
            pq.push_back({child, distances[child]});
            std::push_heap(pq.begin(), pq.end(), compare_min);
        } std::cout << "\n";

        for(int i = 0; i < n; i++) std::cout << distances[i] << " "; std::cout << "\n";
    }

    return distances[target_node];
}

#endif //GRAPHS_ALGORITHM_H
