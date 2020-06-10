#include <iostream>
#include "../src/graphs.h"
#include <vector>

using namespace std;

int main() {

    graph *graph1 = new edgeList;

    bool a = graph1->add_edge({1, 2, 3});
    bool b = graph1->add_edge({1, 3, 4});
    bool c = graph1->add_edge({4, 2, 6});
    bool d = graph1->add_edge({5, 2, 2});
    bool e = graph1->add_edge({2, 3, 5});
    bool f = graph1->add_edge({3, 5, 7});
    cout << "Edges inserted: \t\t\t" << a << b << c << d << e << f << endl;

    int result = mst_prim(graph1);
    cout << "Prim's spanning cost: \t\t"<< result << endl;

    result = mst_kruskal(graph1);
    cout << "Kruskal's spanning cost: \t"<< result << endl;

    return 0;
}