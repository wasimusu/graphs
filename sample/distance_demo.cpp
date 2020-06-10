#include <iostream>
#include "../src/graphs.h"
#include <vector>

using namespace std;

int main() {

    graph *graph1 = new edgeList(true);

    cout << graph1->add_edge({0, 1, 24});
    cout << graph1->add_edge({1, 0, 24});
    cout << graph1->add_edge({0, 3, 20});
    cout << graph1->add_edge({3, 0, 20});
    cout << graph1->add_edge({2, 0, 3});
    cout << graph1->add_edge({0, 2, 3});
    cout << graph1->add_edge({3, 2, 12});
    cout << graph1->add_edge({2, 3, 12});
//    cout << graph1->add_edge({2, 4, 4});
//    cout << graph1->add_edge({4, 2, 4}) << endl;

//    bool a = graph1->add_edge({0, 1, 3});
//    bool b = graph1->add_edge({0, 2, 4});
//    bool c = graph1->add_edge({3, 1, 6});
//    bool d = graph1->add_edge({4, 1, 2});
//    bool e = graph1->add_edge({1, 2, 5});
//    bool f = graph1->add_edge({2, 4, 7});
//    cout << a << b << c << d << e << f << endl;

    auto n = graph1->get_num_nodes();
    cout << n << endl;

    int result = dijkstra_shortest_distance(*graph1, 0, 3);
    cout << result << endl;

    auto dd = all_pair_shortest_path(*graph1);
    n = graph1->get_num_nodes();
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++)
            std::cout << dd[r][c] << " "; std::cout << '\n';
    }

    return 0;
}