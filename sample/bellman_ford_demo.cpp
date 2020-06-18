#include <iostream>
#include "../src/graphs.h"
#include <vector>
#include <cassert>

using namespace std;


void linear_graph() {
    edgeList edgeList(true);
    int num_nodes = 5;
    for (int i = 0; i < num_nodes - 1; i++) {
        edgeList.add_edge({i, i + 1, 1});
    }
    auto res = bellman_ford(edgeList, 0);
    for (int d: res) cout << d << "\t";
    cout << '\n';
}

void random_graph() {
    edgeList edgeList(true);
    edgeList.add_edge({0, 1, 6});
    edgeList.add_edge({0, 2, 5});
    edgeList.add_edge({0, 3, 5});
    edgeList.add_edge({1, 4, -1});
    edgeList.add_edge({2, 1, -2});
    edgeList.add_edge({3, 2, -2});
    edgeList.add_edge({2, 4, 1});
    edgeList.add_edge({3, 5, -1});
    edgeList.add_edge({5, 6, 3});
    edgeList.add_edge({4, 6, 3});

    auto res = bellman_ford(edgeList, 0);
    for (int d: res) cout << d << "\t";
    cout << '\n';

    vector<int> expected = {0, 1, 3, 5, 0, 4, 3};
    assert(equal(res.begin(), res.end(), expected.begin()));
}

void random_graph2() {
    edgeList edgeList(true);
    edgeList.add_edge({2, 1, -10});
    edgeList.add_edge({3, 2, 3});
    edgeList.add_edge({0, 1, 4});
    edgeList.add_edge({0, 3, 5});

    auto actual = bellman_ford(edgeList, 0);
    for (int d: actual) cout << d << "\t";
    cout << '\n';

    vector<int> expected = {0, -2, 8, 5};
    assert(equal(actual.begin(), actual.end(), expected.begin()));
}

void all_pairs_graph() {
    edgeList edgeList(false);
    int num_nodes = 10;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            edgeList.add_edge({i, j, 1});
        }
    }

    auto res = bellman_ford(edgeList, 0);
    for (int d: res) cout << d << "\t";
    cout << '\n';
}

int main() {

    all_pairs_graph();
    linear_graph();
    random_graph2();
    random_graph();

    return 0;
}