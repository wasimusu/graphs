## Graphs
An open-source modern graph library built in C++ for exploring graphs with focus on ease of use.

It uses Google Tests for unit testing and Google Benchmark for benchmarking the library. Measure before optimization.

#### Build Status
<img src="https://travis-ci.com/wasimusu/graphs.svg?branch=master" width="100">

### Features
* Ease of use.
* Easily discoverable member functions
* Lightweight and generic graph representation
* Inputs are ids of nodes. Or let the nodes be decided automatically by the data structure

### Platform
* CMake
* C++11 to C++20
* Clang
* Linux (Xenial/Ubuntu 18.04)

### Build
```
cd graphs
sh install.sh
```

### Data Structures for graph representation
The value of a graph library lies in making it easy to construct and analyze graphs. 
* adjacencyList
* adjacencyMatrix
* edgeList
* Print graphs for easy debugging. Multiple formats for printing graphs

### Algorithms
* Traversals (BFS, DFS, Level Order Traversal)
* Topological Sort
* Prim's Minimum Spanning Tree
* Kruskals' Minimum Spanning Tree
* Dijsktra's Shortest Path Algorithm (May not work for negative edges)
* Floyd Warshall All Pairs Shortest Path Algorithm
* Bellman Ford Shortest Path Algorithm (Works for negative edges)

#### To be published by June 21, 2014
* Connected Components
* Lowest Common Ancestor (Single Query and Multiple Query (Binary Uplifting))
* Tarjan's Strongly Connected Components
* Is the graph bipartite?
* Serialization/deserialization

### Questions that can be solved by graphs
* Find dependency between files. Do topological sort on a graph representing files.
* What is the degree of distance between two people? 
Just find the shortest distance between two people (the edges should have unit weight).
* How many connected components are there in the graph?
* Is there circular dependency in the graph? Or are there loops in the graph?

### Goals
* Double the speed of the whole library.
* Reduce memory consumption and memory leaks

### Todo Devops
* Test the library for multiple versions of C++
* Test the library on multiple OS
* Include bezel build