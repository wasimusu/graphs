## Graphs
An open-source modern graph (&trees) library built in C++ for exploring graphs with focus on ease of use.

It uses Google Tests for unit testing and Google Benchmark for benchmarking the library. Measure before optimization.

#### Build Status
<img src="https://travis-ci.com/wasimusu/graphs.svg?branch=master" width="100">
<img src="https://readthedocs.org/projects/graphs/badge/?version=latest">

### Features
* Ease of use.
* Generic graph representation
* Inputs are ids of nodes. Or let the nodes be decided automatically by the data structure

### Platform
* CMake
* C++11
* Clang
* Linux (Xenial/Ubuntu 18.04)

### Build
As prequisites, CMAKE and git needs to be already installed.
```
cd graphs
sh install.sh
```
### Documentation
A clean succinct documentation will be available on [readthedocs](https://graphs.readthedocs.io/en/latest/) soon.
Until then you can build the document using doxygen.

- Linux
```
cd docs
doxygen
```

- Windows
```
cd docs
doxygen.exe
```


### Data Structures for graph representation
The value of a graph library lies in making it easy to construct and analyze graphs. 
* adjacencyList
* adjacencyMatrix
* edgeList
* (Coming Up) Multiple formats for printing graphs to make it easy to debug them.

### Algorithms
* Traversals (BFS, DFS, Level Order Traversal)
* Topological Sort
* Prim's Minimum Spanning Tree
* Kruskals' Minimum Spanning Tree
* Dijsktra's Shortest Path Algorithm (May not work for negative edges)
* Floyd Warshall All Pairs Shortest Path Algorithm
* Bellman Ford Shortest Path Algorithm (Works for negative edges)

#### TODO: Upcoming features and algorithms
* More constructors for all data structures
* Return list of edges as well as mst cost for minimum spanning tree (mst) queries 
* Connected Components (detect cycles, lca, number of connected components, etc)
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

### Sample usage
This section shows usage of dijkstra's algorithm on a directed graph. For more usage, see the [sample](sample) directory.

```
#include "src/graphs.h"


int main() {
    edgeList edgeList(true); // directed edge list

    edgeList.add_edge(0, 1, 4);
    edgeList.add_edge(0, 2, 2);
    edgeList.add_edge(1, 2, 5);
    edgeList.add_edge(1, 3, 10);
    edgeList.add_edge(2, 4, 3);
    edgeList.add_edge(4, 3, 4);
    edgeList.add_edge(3, 5, 11);

    auto shortest_distance = dijkstra_shortest_distance(edgeList, 0);
    // Expect shortest distance: {0, 4, 2, 9, 5, 20};

    return 0;
}
```

### Goals
* Double the speed of the whole library.
* Reduce memory consumption and memory leaks

### Todo Devops
* Test the library for multiple versions of C++ (14, 17, 20)
* Test the library on multiple OS (MacOS, Windows)
* Include Bazel build
