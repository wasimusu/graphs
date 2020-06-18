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

static void bfs(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        dijkstra_shortest_distance(graph, 0);
    }
}

static void dfs(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        bellman_ford(graph, 0);
    }
}

static void level_order(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        bellman_ford(graph, 0);
    }
}

int num_nodes = 100;
edgeList edgeList(true);
adjacencyMatrix adjacencyMatrix(true);
adjacencyList adjacencyList(true);

BENCHMARK_CAPTURE(build_graph, edgeList, num_nodes, edgeList);
BENCHMARK_CAPTURE(build_graph, adjacencyList, num_nodes, adjacencyList);
BENCHMARK_CAPTURE(build_graph, adjacencyMatrix, num_nodes, adjacencyMatrix);

BENCHMARK_CAPTURE(bfs, edgeList, edgeList);
BENCHMARK_CAPTURE(dfs, edgeList, edgeList);
BENCHMARK_CAPTURE(level_order, edgeList, edgeList);

//BENCHMARK_CAPTURE(bfs, adjacencyList, adjacencyList);
//BENCHMARK_CAPTURE(dfs, adjacencyList, adjacencyList);
//BENCHMARK_CAPTURE(level_order, adjacencyList, adjacencyList);

//BENCHMARK_CAPTURE(bfs, adjacencyMatrix, adjacencyMatrix);
//BENCHMARK_CAPTURE(dfs, adjacencyMatrix, adjacencyMatrix);
//BENCHMARK_CAPTURE(level_order, adjacencyMatrix, adjacencyMatrix);

BENCHMARK_MAIN();