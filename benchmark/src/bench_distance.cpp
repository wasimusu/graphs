#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <vector>

using namespace std;

static void build_graph(benchmark::State &state, int num_nodes, graph &graph) {
    while (state.KeepRunning()) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto added = graph.add_edge({rand() % num_nodes, rand() % num_nodes, rand() % 1000});
            }
        }
    }
}

static void dijkstra(benchmark::State &state, graph& graph) {
    int num_nodes = graph.get_num_nodes();
    while (state.KeepRunning()) {
        dijkstra_shortest_distance(graph, rand() % num_nodes);
    }
}

static void bellman_ford(benchmark::State &state, graph& graph) {
    int num_nodes = graph.get_num_nodes();
    while (state.KeepRunning()) {
        bellman_ford(graph, rand() % num_nodes);
    }
}

static void all_pairs_shortest_path(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        all_pair_shortest_path(graph);
    }
}

int num_nodes = 100;
edgeList edgeList(true);
adjacencyMatrix adjacencyMatrix(true);
adjacencyList adjacencyList(true);

BENCHMARK_CAPTURE(build_graph, edgeList, num_nodes, edgeList);
BENCHMARK_CAPTURE(dijkstra, edgeList, edgeList);
BENCHMARK_CAPTURE(bellman_ford, edgeList, edgeList);
BENCHMARK_CAPTURE(all_pairs_shortest_path, edgeList, edgeList);

//BENCHMARK_CAPTURE(build_graph, adjacencyList, num_nodes, adjacencyList);
//BENCHMARK_CAPTURE(dijkstra, adjacencyList, adjacencyList);
//BENCHMARK_CAPTURE(bellman_ford, adjacencyList, adjacencyList);
//BENCHMARK_CAPTURE(all_pairs_shortest_path, adjacencyList, adjacencyList);

//BENCHMARK_CAPTURE(build_graph, adjacencyMatrix, num_nodes, adjacencyMatrix);
//BENCHMARK_CAPTURE(bellman_ford, adjacencyMatrix, adjacencyMatrix);
//BENCHMARK_CAPTURE(dijkstra, adjacencyMatrix, adjacencyMatrix);
//BENCHMARK_CAPTURE(all_pairs_shortest_path, adjacencyMatrix, adjacencyMatrix);

BENCHMARK_MAIN();