#include <iostream>
#include "../src/graphs.h"
#include <vector>

using namespace std;

void linear_graph() {
    edgeList edgeList;
    edgeList.add_edge({0, 1});
    edgeList.add_edge({1, 2});
    edgeList.add_edge({2, 3});
    edgeList.add_edge({3, 4});

    vector<int> reference_result = {4, 3, 2, 1, 0};
    vector<int> result;
    topological_sort(edgeList.get_num_nodes(), &edgeList, result);

    for (const int node: result) cout << node << "\t";
    cout << endl;

    equal(reference_result.begin(), reference_result.end(), result.begin(), result.end());
}

void random_graph() {
    graph *graph1 = new edgeList;

    bool a = graph1->add_edge({1, 0});
    bool b = graph1->add_edge({2, 0});
    bool c = graph1->add_edge({3, 1});
    bool d = graph1->add_edge({3, 2});
    auto edges = graph1->get_edges();

    vector<int> reference_result = {0, 2, 1, 3};
    vector<int> result;
    topological_sort(4, graph1, result);

    for (const int node: result) cout << node << "\t";
    cout << endl;

    equal(reference_result.begin(), reference_result.end(), result.begin(), result.end());
    delete graph1;
}

int main() {

    linear_graph();
    random_graph();

    return 0;
}