#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <vector>

using namespace std;

static void benchmark_push_back(benchmark::State &state) {
    while (state.KeepRunning()) {
        std::vector<int> v;
        v.push_back(42);
    }
}

BENCHMARK(benchmark_push_back);

BENCHMARK_MAIN();