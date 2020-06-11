/**
 * @brief Implements algorithms to compute minimum spanning tree for graphs
 * */

#pragma once
#ifndef GRAPHS_MST_H
#define GRAPHS_MST_H

/**
 * @brief implements prim's minimum spanning tree
 * Requires weighted edge list
 * @return pair[int, vector<vector<int>>]: returns pair of total minimum cost and the nodes that will span the tree
 * */
int mst_prim(graph *graph) {
    // Let's assume that there is no starting point

    // Comparator for a min-heap
    auto compare = [](const std::vector<int> &edgeA, const std::vector<int> &edgeB) {
        return edgeA[2] > edgeB[2];
    };

    auto edge_list = graph->get_edges();
    std::make_heap(edge_list.begin(), edge_list.end(), compare);

    int min_cost = 0;
    std::unordered_set<int> visited;

    int n = edge_list.size();
    int start_node, end_node, cost = 0; // initialize variables describing an edge
    for (int i = 0; i < n; i++) {
        start_node = edge_list[0][0], end_node = edge_list[0][1], cost = edge_list[0][2];

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
 * @brief implements kruskal's minimum spanning tree
 * Requires weighted edge list
 * */
int mst_kruskal(graph *graph) {

    // Comparator for a min-heap
    auto compare = [](const std::vector<int> &edgeA, const std::vector<int> &edgeB) {
        return edgeA[2] > edgeB[2];
    };

    auto edge_list = graph->get_edges();
    std::make_heap(edge_list.begin(), edge_list.end(), compare);
    std::unordered_set<int> explore{};
    std::vector<std::vector<int>> pq{edge_list[0]};
    int min_cost = 0;
    std::vector<int> visited(edge_list.size(), false);
    visited[0] = true;

    for (int i = 0; i < edge_list.size(); i++) {
        auto edge = pq[0];
        std::pop_heap(pq.begin(), pq.end(), compare);
        pq.pop_back();

        if (explore.count(edge[0]) && explore.count(edge[1])) continue;

        explore.insert(edge[0]);
        explore.insert(edge[1]);
        min_cost += edge[2];

        // Add new edges to the list of exploration
        for (int i = 1; i < edge_list.size(); i++) {
            if (visited[i]) continue;
            auto &_edge = edge_list[i];

            if (!(explore.count(_edge[0]) ^ explore.count(_edge[1]))) continue;

            pq.push_back(_edge);
            std::push_heap(pq.begin(), pq.end(), compare);
            visited[i] = true;
        }

        if (pq.empty()) break;
    }

    return min_cost;
}


#endif //GRAPHS_MST_H
