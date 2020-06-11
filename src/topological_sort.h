#pragma once
#ifndef GRAPHS_TOPOLOGICAL_SORT_H
#define GRAPHS_TOPOLOGICAL_SORT_H

#include <algorithm>

/**
 * If the nodes are not enumerated in 0 base, then there is segfault and allocated memory won't be released
 * */
void topological_sort(graph *graph, std::vector<int> &result) {

    auto adjacent = graph->get_adjacentMatrix();
    int *indegree = graph->get_indegree();
    int num_nodes = graph->get_num_nodes();

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

    std::reverse(result.begin(), result.end());

    for (int i = 0; i < num_nodes; i++) {
        delete[] adjacent[i];
    }
    delete[] adjacent;
    delete[] indegree;
}


#endif //GRAPHS_TOPOLOGICAL_SORT_H
