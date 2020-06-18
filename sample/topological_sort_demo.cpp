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

    vector<int> expected_result = {4, 3, 2, 1, 0};
    vector<int> actual_result;
    topological_sort(&edgeList, actual_result);

    for (const int node: actual_result) cout << node << "\t";
    cout << endl;

    std::equal(expected_result.begin(), expected_result.end(), actual_result.begin());
}

void random_graph() {
    graph *graph = new edgeList;

    bool a = graph->add_edge({1, 0});
    bool b = graph->add_edge({2, 0});
    bool c = graph->add_edge({3, 1});
    bool d = graph->add_edge({3, 2});
    auto edges = graph->get_edges();

    vector<int> expected_result = {0, 2, 1, 3};
    vector<int> actual_result;
    topological_sort(graph, actual_result);

    for (const int node: actual_result) cout << node << "\t";
    cout << endl;

    std::equal(expected_result.begin(), expected_result.end(), actual_result.begin());
    delete graph;
}

int main() {

    linear_graph();
    random_graph();

    return 0;
}