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
//directed_graph.add_edge({0, 1, 6});
//edgeList.add_edge({0, 2, 5});
//edgeList.add_edge({0, 3, 5});
//edgeList.add_edge({1, 4, -1});
//edgeList.add_edge({2, 1, -2});
//edgeList.add_edge({3, 2, -2});
//edgeList.add_edge({2, 4, 1});
//edgeList.add_edge({3, 5, -1});
//edgeList.add_edge({5, 6, 3});
//edgeList.add_edge({4, 6, 3});


edgeList undirected_graph(false);

BENCHMARK_CAPTURE(benchmark_dijkstra, directed, directed_graph);
BENCHMARK_CAPTURE(benchmark_dijkstra, undirected, undirected_graph);
BENCHMARK_CAPTURE(benchmark_bellman_ford, directed, directed_graph);
BENCHMARK_CAPTURE(benchmark_bellman_ford, undirected, undirected_graph);
BENCHMARK_CAPTURE(benchmark_all_pairs_shortest_path, directed, directed_graph);
BENCHMARK_CAPTURE(benchmark_all_pairs_shortest_path, undirected, undirected_graph);

BENCHMARK_MAIN();