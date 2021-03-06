#include <benchmark/benchmark.h>
#include "../../src/graphs.h"

static void build_graph(benchmark::State &state, int num_nodes, graph &graph) {
    while (state.KeepRunning()) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto added = graph.add_edge({rand() % num_nodes, rand() % num_nodes, rand() % 1000});
            }
        }
    }
}

static void prim(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        auto mst = mst_prim(graph);
    }
}

static void kruskal(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        auto mst = mst_kruskal(graph);
    }
}

int num_nodes = 100;
edgeList edgeList(true);
adjacencyMatrix adjacencyMatrix(true);
adjacencyList adjacencyList(true);

BENCHMARK_CAPTURE(build_graph, edgeList, num_nodes, edgeList);
BENCHMARK_CAPTURE(prim, edgeList, edgeList);
BENCHMARK_CAPTURE(kruskal, edgeList, edgeList);

//BENCHMARK_CAPTURE(build_graph, adjacencyList, num_nodes, adjacencyList);
//BENCHMARK_CAPTURE(prim, adjacencyList, adjacencyList);
//BENCHMARK_CAPTURE(kruskal, adjacencyList, adjacencyList);

//BENCHMARK_CAPTURE(build_graph, adjacencyMatrix, num_nodes, adjacencyMatrix);
//BENCHMARK_CAPTURE(prim, adjacencyMatrix, adjacencyMatrix);
//BENCHMARK_CAPTURE(kruskal, adjacencyMatrix, adjacencyMatrix);

BENCHMARK_MAIN();