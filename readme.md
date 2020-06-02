## Graphs
An open-source modern graph library built for speed in C++.

### Features
* Easily discoverable member functions
* Lightweight and generic graph representation
* Inputs are ids of nodes. Or let the nodes be decided automatically by the data structure

### Platform
* CMake
* C++11 to C++20
* Ubuntu 18.04

### Build
```
cd graphs
mkdir build
cd mkdir
cmake ..
make
```

### Algorithms (To be published by June 7, 2020)
* Three different representation of graph - adjacency matrix, adjacency list, edge list
The value of a graph library lies in making it easy to construct and analyze graphs. 
* Traversals (BFS, DFS)
* Print graphs for easy debugging. Multiple formats for printing graphs
* Prim's Minimum Spanning Tree
* Kruskals' Minimum Spanning Tree
* Dijsktra's Shortest Path Algorithm
* Topological Sort
* Connected Components
* Lowest Common Ancestor (Single Query and Multiple Query (Binary Uplifting))
* Floyd Warshall All Pairs Shortest Path Algorithm
* Tarjan's Strongly Connected Components
* Bellman Ford Algorithm
* Is the graph bipartite?


### Upcoming features/development
* Benchmarks
* Google Tests

### Questions that can be solved by graphs
* Find dependency between files.
* What is the degree of distance between two people?
* How many connected components are there in the graph?