/**
 * @brief Implements algorithms to compute minimum spanning tree for graphs
 * */

#ifndef GRAPHS_MST_H
#define GRAPHS_MST_H
#pragma once

#include "unionfind.h"

/**
 * @brief implements kruskal's minimum spanning tree
 * Keep adding minimum edges and don't form cycle.
 * Requires weighted edge list
 * */
int mst_kruskal(graph& graph) {
    int n = graph.get_num_nodes();
    union_find disjoint_set(n);

    // Comparator for a min-heap
    auto compare = [](const std::vector<int> &edgeA, const std::vector<int> &edgeB) {
        return edgeA[2] > edgeB[2];
    };

    auto edge_list = graph.get_edges();
    std::make_heap(edge_list.begin(), edge_list.end(), compare);

    int min_cost = 0;

    int num_edges = edge_list.size();
    int start_node, end_node, cost = 0; // variables describing an edge
    for (int i = 0; i < num_edges; i++) {
        start_node = edge_list[0][0], end_node = edge_list[0][1], cost = edge_list[0][2];

        std::pop_heap(edge_list.begin(), edge_list.end(), compare);
        edge_list.pop_back();

        if (disjoint_set.has_same_parent(start_node, end_node)) continue;
        disjoint_set.join(start_node, end_node);

        min_cost += cost;
    }

    return min_cost;
}


/**
 * @brief implements prim's minimum spanning tree
 * Requires weighted edge list
 * */
int mst_prim(graph& graph) {

    // Comparator for a min-heap
    auto compare = [](const std::vector<int> &edgeA, const std::vector<int> &edgeB) {
        return edgeA[2] > edgeB[2];
    };

    auto edge_list = graph.get_edges();
    std::make_heap(edge_list.begin(), edge_list.end(), compare);
    std::unordered_set<int> explore{};
    std::vector<std::vector<int>> pq{edge_list[0]};

    int min_cost = 0;
    std::vector<int> visited(edge_list.size(), false);
    visited[0] = true;

    for (int i = 0; i < edge_list.size(); i++) {
        if (pq.empty()) break;
        auto edge = pq[0];
        std::pop_heap(pq.begin(), pq.end(), compare);
        pq.pop_back();

        if (explore.count(edge[0]) && explore.count(edge[1])) continue;

        explore.insert(edge[0]);
        explore.insert(edge[1]);
        min_cost += edge[2];

        // Add new edges to the list of exploration
        for (int j = 1; j < edge_list.size(); j++) {
            if (visited[j]) continue;
            auto &_edge = edge_list[j];

            if (!(explore.count(_edge[0]) ^ explore.count(_edge[1]))) continue;

            pq.push_back(_edge);
            std::push_heap(pq.begin(), pq.end(), compare);
            visited[j] = true;
        }
    }

    return min_cost;
}


#endif //GRAPHS_MST_H
