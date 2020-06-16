#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <vector>

using namespace std;

static void benchmark_prim(benchmark::State &state, graph& graph) {
    while (state.KeepRunning()) {
        dijkstra_shortest_distance(graph, 0);
    }
}

static void benchmark_kruskal(benchmark::State &state, graph& graph) {
    while (state.KeepRunning()) {
        bellman_ford(graph, 0);
    }
}

edgeList directed_graph(true);
edgeList undirected_graph(false);

BENCHMARK_CAPTURE(benchmark_prim, directed, directed_graph);
BENCHMARK_CAPTURE(benchmark_prim, undirected, undirected_graph);
BENCHMARK_CAPTURE(benchmark_kruskal, directed, directed_graph);
BENCHMARK_CAPTURE(benchmark_kruskal, undirected, undirected_graph);

BENCHMARK_MAIN();