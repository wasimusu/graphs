#include <iostream>
#include "../src/graphs.h"
#include <vector>
#include <cassert>

using namespace std;

int main() {

    graph *graph = new edgeList;

    bool a = graph->add_edge({1, 2, 3});
    bool b = graph->add_edge({1, 3, 4});
    bool c = graph->add_edge({4, 2, 6});
    bool d = graph->add_edge({5, 2, 2});
    bool e = graph->add_edge({2, 3, 5});
    bool f = graph->add_edge({3, 5, 7});
    assert(a && b && c && d && e && f == 1);
    cout << "Edges inserted: \t\t\t" << a << b << c << d << e << f << endl;

    int result = mst_prim(*graph);
    cout << "Prim's spanning cost: \t\t" << result << endl;

    result = mst_kruskal(*graph);
    cout << "Kruskal's spanning cost: \t" << result << endl;

    return 0;
}