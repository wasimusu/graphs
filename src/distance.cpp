#include "distance.h"

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
