#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <iostream>

using namespace std;

static void bench_union(benchmark::State &state, union_find &union_find) {
    size_t size = union_find.size();
    while (state.KeepRunning()) {
        int trial = 100;
        for (int i = 0; i < trial; i++) {
            auto status = union_find.join(rand() % size, rand() % size);
        }
    }
}

static void bench_merge(benchmark::State &state, union_find &union_find) {
    size_t size = union_find.size();
    while (state.KeepRunning()) {
        int trial = 100;
        for (int i = 0; i < trial; i++) {
            auto status = union_find.join(rand() % size, rand() % size);
        }
    }
}

static void bench_has_same_parents(benchmark::State &state, union_find &union_find) {
    size_t size = union_find.size();
    while (state.KeepRunning()) {
        int trial = 100;
        for (int i = 0; i < trial; i++) {
            auto status = union_find.has_same_parent(rand() % size, rand() % size);
        }
    }
}

static void bench_find_parent(benchmark::State &state, union_find &union_find) {
    size_t size = union_find.size();
    while (state.KeepRunning()) {
        int trial = 100;
        for (int i = 0; i < trial; i++) {
            auto result = union_find.find_parent(rand() % size);
        }
    }
}


// Benchmark edgeList
int n = 1000;
union_find union_find(n);
BENCHMARK_CAPTURE(bench_union, union_find, union_find);
BENCHMARK_CAPTURE(bench_merge, union_find, union_find);
BENCHMARK_CAPTURE(bench_find_parent, union_find, union_find);
BENCHMARK_CAPTURE(bench_has_same_parents, union_find, union_find);

BENCHMARK_MAIN();