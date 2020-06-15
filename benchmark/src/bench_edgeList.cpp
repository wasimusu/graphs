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

BENCHMARK(benchmark_push_back);

BENCHMARK_MAIN();