#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <vector>

using namespace std;

static void benchmark_bfs(benchmark::State &state, graph& graph) {
    while (state.KeepRunning()) {
        dijkstra_shortest_distance(graph, 0);
    }
}

static void benchmark_dfs(benchmark::State &state, graph& graph) {
    while (state.KeepRunning()) {
        bellman_ford(graph, 0);
    }
}

static void benchmark_level_order(benchmark::State &state, graph& graph) {
    while (state.KeepRunning()) {
        bellman_ford(graph, 0);
    }
}

edgeList directed_graph(true);
edgeList undirected_graph(false);

BENCHMARK_CAPTURE(benchmark_bfs, directed_graph);
BENCHMARK_CAPTURE(benchmark_bfs, undirected_graph);
BENCHMARK_CAPTURE(benchmark_dfs, directed_graph);
BENCHMARK_CAPTURE(benchmark_dfs, undirected_graph);
BENCHMARK_CAPTURE(benchmark_level_order, directed_graph);
BENCHMARK_CAPTURE(benchmark_level_order, undirected_graph);

BENCHMARK_MAIN();