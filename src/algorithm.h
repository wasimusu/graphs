#ifndef GRAPHS_ALGORITHM_H
#define GRAPHS_ALGORITHM_H

#include "graph.h"
#include <iostream>
#include <algorithm>

void bfs(graph &graph, int start, std::vector<int> result);

void dfs(graph &graph, int start, std::vector<int> result);

void topological_sort(int num_nodes, graph *graph, std::vector<int> &result) {

    auto adjacent = graph->get_adjacentMatrix();
    int* indegree = graph->get_indegree();

    std::deque<int> source;
    for(int node = 0; node < num_nodes; node++){
        if (indegree[node] == 0){
            source.push_back(node);
        }
    }

    while(!source.empty()){
        const auto node = source.front();
        source.pop_front();
        result.push_back(node);

        auto prereq = adjacent[node];
        for(int i = 0; i < num_nodes; i++){
            int child = prereq[i];
            if (child == 0) continue;
            indegree[i] -= 1;
            if (indegree[i] == 0){
                source.push_back(i);
            }
        }
    }

    reverse(result.begin(), result.end());
}

#endif //GRAPHS_ALGORITHM_H
