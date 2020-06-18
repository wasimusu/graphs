#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <vector>


static void build_graph(benchmark::State &state, int num_nodes, graph &graph) {
    while (state.KeepRunning()) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto added = graph.add_edge({rand() % num_nodes, rand() % num_nodes, rand() % 1000});
            }
        }
    }
}


static void topsort(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        std::vector<int> result;
        topological_sort(&graph, result);
    }
}

int num_nodes = 100;
edgeList edgeList(true);
adjacencyMatrix adjacencyMatrix(true);
adjacencyList adjacencyList(true);

BENCHMARK_CAPTURE(build_graph, edgeList, num_nodes, edgeList);
BENCHMARK_CAPTURE(topsort, edgeList, edgeList);

//BENCHMARK_CAPTURE(build_graph, adjacencyList, num_nodes, adjacencyList);
//BENCHMARK_CAPTURE(topsort, adjacencyList, adjacencyList);

//BENCHMARK_CAPTURE(build_graph, adjacencyMatrix, num_nodes, adjacencyMatrix);
//BENCHMARK_CAPTURE(topsort, adjacencyMatrix, adjacencyMatrix);

BENCHMARK_MAIN();