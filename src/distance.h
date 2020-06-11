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
int dijkstra_shortest_distance(graph &graph, int source_node, int target_node) {

    auto adjacent = graph.get_adjacentMatrix();
    int n = graph.get_num_nodes();
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
        auto[node, cost] = pq[0];
        std::pop_heap(pq.begin(), pq.end(), compare_min);
        pq.pop_back();

        if (visited[node]) continue;
        visited[node] = true;

        auto adj_list = adjacent[node];
        for (int child = 0; child < n; child++) {
            int weight = adj_list[child];
            if (weight == 0) continue;
            if (visited[child]) continue;
            distances[child] = std::min(distances[child], adjacent[node][child] + cost);
            pq.push_back({child, distances[child]});
            std::push_heap(pq.begin(), pq.end(), compare_min);
        }
    }

//    for (int i = 0; i < n; i++) {
//        delete[] adjacent[i];
//    }
//    delete[] adjacent;

    return distances[target_node];
}

/*
 * @brief: Computes all pair shortest path using floyd's all path shortest path algorithm.
 * As long as there is no cycle, this algorithm works fine.
 * reference: https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 *
 * @param[graph] graph: input graph
 * @returns[int**] distances: 2D array containing distance between each pair of nodes
 * **/
int **all_pair_shortest_path(graph &graph) {
    auto distances = graph.get_adjacentMatrix();
    int n = graph.get_num_nodes();

    // Change the adjancent matrix into distance matrix. No connection implies infinite distance.
    std::replace(*distances, *distances + n * n, 1, std::numeric_limits<int>::max());

    for (int rc = 0; rc < n; rc++) {
        for (int r = 0; r < n; r++) {
            if (rc == r) continue;
            for (int c = 0; c < n; c++) {
                if (rc == c || r == c) continue;
                distances[r][c] = std::min(distances[r][rc] + distances[rc][c], distances[r][c]);
            }
        }
    }

    return distances;
}

/**
 * @brief Implements Bellman Ford algorithm to find shortest distances when the edges are negative
 * Note: Does not work when the total weight of the cycle is negative
 *
 * @param[int]source_node: The source node from which shortest distance is to be computed
 * @param[graph]graph: Input graph on which shortest distance is to be computed
 * @returns[std::vector<int>] distances: shortest distance from source_node to all other nodes
 * @throws: std::invalid_argument error if the graph is not weighted.
 **/
std::vector<int> bellman_ford(graph &graph, const int source_node) {
    int n = graph.get_num_nodes();
    std::vector<int> distances(n, std::numeric_limits<int>::max());
    distances[source_node] = 0;
    auto edges = graph.get_edges();
    if (edges[0][2] == 0)
        throw std::invalid_argument("Weighted edges required for Bellman Ford algorithm. Unweighted edges provided");

    // Relax all edges n - 1 times
    for (int i = 0; i < n - 1; i++) {
        for (const auto &edge: edges) {
            int start = edge[0], end = edge[1], cost = edge[2];
            if (distances[start] == std::numeric_limits<int>::max()) continue;
            distances[end] = std::min(distances[end], distances[start] + cost);
        }
    }

    return distances;
}

#endif //GRAPHS_DISTANCE_H