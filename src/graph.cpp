#include <bits/stdc++.h>

using namespace std;

class graph {
private:
public:
    graph() = default;

    virtual ~graph() = default;

    virtual bool add_edge() = 0;

    virtual bool add_vertex() { return false; }
};


class adjacencyList : public graph {
private:
    unordered_map<int, vector<int>> adjList;
public:
    adjacencyList() = default;

    bool add_edge(int start, int end, int weight = 0) {
        if (find(adjList[start].begin(), adjList[start].end(), end) == adjList[start].end())
            return false;

        adjList[start].push_back(end);
        adjList[end].push_back(start);
        return true;
    }

    ~adjacencyList() override = default;
};

class edgeList : public graph {
private:
    unordered_map<int, int> edges;

public:
    edgeList() = default;

    bool add_edge(int start, int end, int weight = 0) {
        if (edges.count(start) == 1) return false;
        edges.insert({start, end});
        edges.insert({end, start});
        return true;
    }

    ~edgeList() override = default;
};

class adjanceyMatrix : public graph {
private:
    int **adjMatrix;
    int num_nodes = 0;
public:
    explicit adjanceyMatrix(const int num_nodes) : num_nodes(num_nodes) {
        adjMatrix = new int *[num_nodes];
        for (int i = 0; i < num_nodes; i++) {
            adjMatrix[i] = new int[num_nodes];
        }
    }

    bool add_edge(int start, int end, int weight = 0) {
        if (start < 0 || end < 0 || start >= num_nodes || end >= num_nodes || adjMatrix[start][end] == 1) return false;

        adjMatrix[start][weight] = 1;
        return true;
    }

    ~adjanceyMatrix() override {
        for (int i = 0; i < num_nodes; i++) {
            delete[] adjMatrix[i];
        }
    };
};

int main() {
    return 0;
}
