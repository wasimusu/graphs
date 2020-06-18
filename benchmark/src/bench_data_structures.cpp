#include <benchmark/benchmark.h>
#include "../../src/graphs.h"
#include <iostream>

using namespace std;

static void add_edges_ints(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        int num_nodes = 100;
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto added = graph.add_edge(i, j);
            }
        }
    }
}

static void add_random_edges(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        int num_nodes = 100;
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto added = graph.add_edge({rand() % num_nodes, rand() % num_nodes});
            }
        }
    }
}

static void add_edges_vector(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        int num_nodes = 100;
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto added = graph.add_edge({i, j});
            }
        }
    }
}

static void remove_edges_vector(benchmark::State &state, graph &graph) {
    const int num_nodes = graph.get_num_nodes();
    while (state.KeepRunning()) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto removed = graph.remove_edge({i, j});
            }
        }
    }
}

static void remove_edges_int(benchmark::State &state, graph &graph) {
    const int num_nodes = graph.get_num_nodes();
    while (state.KeepRunning()) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                auto removed = graph.remove_edge(i, j);
            }
        }
    }
}

static void get_indegree(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        graph.get_indegree();
    }
}

static void get_adjMatrix(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        graph.get_adjacentMatrix();
    }
}

static void get_adjList(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        graph.get_adjacentList();
    }
}

static void get_edges(benchmark::State &state, graph &graph) {
    while (state.KeepRunning()) {
        graph.get_edges();
    }
}


// Benchmark edgeList
edgeList edgeList(true), edgeList1(true);
BENCHMARK_CAPTURE(add_edges_vector, edgeList, edgeList);

BENCHMARK_CAPTURE(get_indegree, edgeList, edgeList);
BENCHMARK_CAPTURE(get_adjList, edgeList, edgeList);
BENCHMARK_CAPTURE(get_adjMatrix, edgeList, edgeList);
BENCHMARK_CAPTURE(get_edges, edgeList, edgeList);

//BENCHMARK_CAPTURE(add_edges_ints, edgeList, edgeList);
//BENCHMARK_CAPTURE(add_random_edges, edgeList, edgeList2);

BENCHMARK_CAPTURE(remove_edges_int, edgeList, edgeList);
//BENCHMARK_CAPTURE(remove_edges_vector, edgeList, edgeList);


// Benchmark adjacencyList
adjacencyList adjacencyList(true), adjacencyList1(true);
BENCHMARK_CAPTURE(add_edges_vector, adjacencyList, adjacencyList);

BENCHMARK_CAPTURE(get_indegree, adjacencyList, adjacencyList);
BENCHMARK_CAPTURE(get_adjList, adjacencyList, adjacencyList);
BENCHMARK_CAPTURE(get_adjMatrix, adjacencyList, adjacencyList);
BENCHMARK_CAPTURE(get_edges, adjacencyList, adjacencyList);

//BENCHMARK_CAPTURE(add_edges_ints, directed, adjacencyList);
//BENCHMARK_CAPTURE(add_random_edges, directed, adjacencyList1);

BENCHMARK_CAPTURE(remove_edges_int, adjacencyList, adjacencyList);
//BENCHMARK_CAPTURE(remove_edges_vector, adjacencyList, adjacencyList);


// Benchmark adjacencyMatrix
adjacencyMatrix adjacencyMatrix(true), adjacencyMatrix1(true);
BENCHMARK_CAPTURE(add_edges_vector, adjacencyMatrix, adjacencyMatrix);

BENCHMARK_CAPTURE(get_indegree, adjacencyMatrix, adjacencyMatrix);
BENCHMARK_CAPTURE(get_adjList, adjacencyMatrix, adjacencyMatrix);
BENCHMARK_CAPTURE(get_adjMatrix, adjacencyMatrix, adjacencyMatrix);
BENCHMARK_CAPTURE(get_edges, adjacencyMatrix, adjacencyMatrix);

BENCHMARK_CAPTURE(remove_edges_int, adjacencyMatrix, adjacencyMatrix);
//BENCHMARK_CAPTURE(remove_edges_vector, adjacencyMatrix, adjacencyMatrix);

//BENCHMARK_CAPTURE(add_edges_ints, adjacencyMatrix, adjacencyMatrix);
//BENCHMARK_CAPTURE(add_random_edges, adjacencyMatrix, adjacencyMatrix1);

BENCHMARK_MAIN();