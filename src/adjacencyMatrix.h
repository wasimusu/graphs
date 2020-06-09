#pragma once
#ifndef GRAPHS_ADJACENCYMATRIX_H
#define GRAPHS_ADJACENCYMATRIX_H

#include "graph.h"

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

    bool add_edge(int start, int end, int weight = 0) override {
        if (start < 0 || end < 0 || start >= num_nodes || end >= num_nodes || adjMatrix[start][end] == 1) return false;

        adjMatrix[start][end] = 1;
        return true;
    }

    ~adjanceyMatrix() override {
        for (int i = 0; i < num_nodes; i++) {
            delete[] adjMatrix[i];
        }
    };
};

#endif //GRAPHS_ADJACENCYMATRIX_H
