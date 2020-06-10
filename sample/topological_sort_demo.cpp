#include <iostream>
#include "../src/graphs.h"
#include <vector>

using namespace std;

int main() {

    graph *graph1 = new edgeList;

    bool a = graph1->add_edge({1, 0});
    bool b = graph1->add_edge({2, 0});
    bool c = graph1->add_edge({3, 1});
    bool d = graph1->add_edge({3, 2});
    cout << a << b << c << d << endl;
    auto edges = graph1->get_edges();
//    cout << edges << endl;
//    graph1->print_edges();

    vector<int> result;
    topological_sort(4, graph1, result);
    cout << result.size() << endl;
    for (const int node: result) cout << node << "\t";
    cout << endl;

    return 0;
}