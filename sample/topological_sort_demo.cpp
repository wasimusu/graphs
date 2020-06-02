#include <iostream>
#include "../src/graphs.h"
#include <vector>

using namespace std;

int main() {

    graph *graph1 = new edgeList;
    graph1->add_edge(1, 0);
    graph1->add_edge(2, 0);
    graph1->add_edge(3, 1);
    graph1->add_edge(3, 2);

    vector<int> result;
    topological_sort(4, graph1, result);
    for (const int node: result) cout << node << "\t";
    cout << endl;

    return 0;
}