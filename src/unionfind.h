/**
 * Implementation of union find structure.
 * Used in the implementation of kruskal's minimum spanning tree
 * */

#pragma once
#ifndef GRAPHS_UNIONFIND_H
#define GRAPHS_UNIONFIND_H

#include <iostream>
class union_find {
private:
    std::vector<int> sets;
    std::vector<int> parent;
    const int _size;
public:
    union_find(const int size) : _size(size) {
        sets.reserve(size);
        parent.reserve(size);
        for (int i = 0; i < _size; i++) {
            sets.push_back(i);
            parent.push_back(i);
        }
    }

    int size() const {
        return _size;
    }

    int find_parent(int child) {
        if (parent[child] == child) return child;
        return find_parent(parent[child]);
    }

    bool join(const int first, const int second) {
        int first_parent = find_parent(first);
        int second_parent = find_parent(second);

        if (first_parent == second_parent) return false;
        int max_parent = std::max(first_parent, second_parent);
        int min_parent = std::min(first_parent, second_parent);

        std::replace(parent.begin(), parent.end(), min_parent, max_parent);
        return true;
    }

    bool has_same_parent(const int first, const int second) {
        return find_parent(first) == find_parent(second);
    }

    ~union_find() = default;
};


#endif //GRAPHS_UNIONFIND_H
