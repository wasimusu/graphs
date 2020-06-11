#pragma once
#ifndef GRAPHS_TOPOLOGICAL_SORT_H
#define GRAPHS_TOPOLOGICAL_SORT_H

#include <algorithm>

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

    std::reverse(result.begin(), result.end());
//    delete[] indegree;
}


#endif //GRAPHS_TOPOLOGICAL_SORT_H
