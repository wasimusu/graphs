#ifndef GRAPHS_DISTANCE_H
#define GRAPHS_DISTANCE_H


/*
 * Implements dijsktra's shortest path algorithm to find the shortest distance between source_node and all
 * other nodes in the graph.
 * Assumes the nodes are enumerated in 0 base.
 * **/
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
        auto[node, cost] = pq[0];
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
        }
        std::cout << "\n";

        for (int i = 0; i < n; i++) std::cout << distances[i] << " ";
        std::cout << "\n";
    }

    return distances[target_node];
}

/*
 * @brief: Computes all pair shortest path using floyd's all path shortest path algorithm
 * reference: https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 *
 * **/
void all_pair_shortest_path() {

}


#endif //GRAPHS_DISTANCE_H