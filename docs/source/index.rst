Welcome to Graphs's documentation!
==================================
An open-source modern graph (&trees) library built in C++ for exploring graphs with focus on ease of use.

It uses Google Tests for unit testing and Google Benchmark for benchmarking the library. Measure before optimization.

Data Structures for graph representation
----------------------------------------
The value of a graph library lies in making it easy to construct and analyze graphs.

* adjacencyList
* adjacencyMatrix
* edgeList
* (Coming Up) Multiple formats for printing graphs to make it easy to debug them.

Algorithms
----------
* Traversals (BFS, DFS, Level Order Traversal)
* Topological Sort
* Prim's Minimum Spanning Tree
* Kruskals' Minimum Spanning Tree
* Dijsktra's Shortest Path Algorithm (May not work for negative edges)
* Floyd Warshall All Pairs Shortest Path Algorithm
* Bellman Ford Shortest Path Algorithm (Works for negative edges)

.. toctree::
   :maxdepth: 2
   :caption: Contents:

Sample usage
------------
This section shows usage of dijkstra's algorithm on a directed graph.
For more usage, see the sample directory directory on github.

.. code-block:: cpp
   :name: dijkstra.cpp

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

API References
==============
:doc:`Graph Algorithm APIs <algorithm>`

:doc:`Graph Data structures APIs <datastructure>`

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
