#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <vector>

using namespace std;

static void benchmark_dijkstra(benchmark::State &state, graph& graph) {
    while (state.KeepRunning()) {
        dijkstra_shortest_distance(graph, 0);
    }
}

static void benchmark_bellman_ford(benchmark::State &state, graph& graph) {
    while (state.KeepRunning()) {
        bellman_ford(graph, 0);
    }
}

static void benchmark_all_pairs_shortest_path(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        all_pair_shortest_path(graph);
    }
}

edgeList directed_graph(true);
edgeList undirected_graph(false);

BENCHMARK_CAPTURE(benchmark_dijkstra, directed_graph);
BENCHMARK_CAPTURE(benchmark_dijkstra, undirected_graph);
BENCHMARK_CAPTURE(benchmark_bellman_ford, directed_graph);
BENCHMARK_CAPTURE(benchmark_bellman_ford, undirected_graph);
BENCHMARK_CAPTURE(benchmark_all_pairs_shortest_path, directed_graph);
BENCHMARK_CAPTURE(benchmark_all_pairs_shortest_path, undirected_graph);

BENCHMARK_MAIN();