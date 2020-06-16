#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <vector>

using namespace std;

static void benchmark_add_edges(benchmark::State &state) {
    while (state.KeepRunning()) {
        edgeList edgeList(true);
        int num_nodes = 1000;
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto added = edgeList.add_edge({i, j});
            }
        }
    }
}

static void benchmark_remove_edges(benchmark::State &state) {
    while (state.KeepRunning()) {
    }
}

BENCHMARK(benchmark_add_edges);

BENCHMARK_MAIN();