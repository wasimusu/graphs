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
    cout << a << b << c << d << e << f << endl;

    auto n = graph1->get_num_nodes();
    cout << n << endl;

//    graph1->print_edges();

    int result = mst_prim(graph1);
    cout << result << endl;

    return 0;
}