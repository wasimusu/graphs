## Graphs
An open-source modern graph library built in C++ for exploring graphs.

### Features
* Ease of use.
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

### Data Structures for graph representation
The value of a graph library lies in making it easy to construct and analyze graphs. 
* adjacencyList
* adjacencyMatrix
* edgeList

### Algorithms (To be published by June 14, 2020)
* Traversals (BFS, DFS, Level Order Traversal)
* Topological Sort
* Print graphs for easy debugging. Multiple formats for printing graphs
* Prim's Minimum Spanning Tree
* Kruskals' Minimum Spanning Tree
* Dijsktra's Shortest Path Algorithm

#### To be published by June 14, 2014
* Connected Components
* Lowest Common Ancestor (Single Query and Multiple Query (Binary Uplifting))
* Floyd Warshall All Pairs Shortest Path Algorithm
* Tarjan's Strongly Connected Components
* Bellman Ford Algorithm
* Is the graph bipartite?
* Serialization/deserialization

### Upcoming features/development
* Benchmarks
* Google Tests

### Questions that can be solved by graphs
* Find dependency between files. Do topological sort on a graph representing files.
* What is the degree of distance between two people? 
Just find the shortest distance between two people (the edges should have unit weight).
* How many connected components are there in the graph?
* Is there circular dependency in the graph? Or are there loops in the graph?

### Goals
* Double the speed of the whole library.
* Reduce memory consumption