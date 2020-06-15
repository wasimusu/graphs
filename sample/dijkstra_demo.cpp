#include <iostream>
#include "../src/graphs.h"
#include <vector>

using namespace std;


void linear_graph() {
    edgeList edgeList(false);
    int num_nodes = 10;
    for (int i = 0; i < num_nodes - 1; i++) {
        edgeList.add_edge({i, i + 1, 1});
    }

    for (int start = 0; start < num_nodes; start++) {
        for (int end = 0; end < num_nodes; end++) {
            auto res = dijkstra_shortest_distance(edgeList, start);
            std::cout << res[end] << "\t" << abs(end - start) << "\n";
        }
    }
}


void all_pairs_graph() {
    edgeList edgeList(false);
    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            edgeList.add_edge({i, j, 1});
        }
    }

    for (int start = 0; start < num_nodes; start++) {
        for (int end = 0; end < num_nodes; end++) {
            if (start == end) continue;
            auto res = dijkstra_shortest_distance(edgeList, start);
            std::cout << res[end] << "\t" << 1 << "\n";
        }
    }
}

int main() {

    all_pairs_graph();
    std::cout << std::endl;
    linear_graph();

    return 0;
}