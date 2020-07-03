/**
 * @file
 * @brief Aggregates all data structures and algorithms in a single header file.
 * Allows users to just include a single header file to use any feature
 * */

#pragma once
#ifndef GRAPHS_GRAPHS_H
#define GRAPHS_GRAPHS_H

// Data structures
#include "graph.h"
#include "edgeList.h"
#include "adjacencyList.h"
#include "adjacencyMatrix.h"
#include "unionfind.h"

// Algorithms
#include "mst.h"
#include "topological_sort.h"
#include "traverse.cpp"
#include "distance.cpp"
#include "connectivity.cpp"

#endif //GRAPHS_GRAPHS_H
