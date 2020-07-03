/**
 * @file
 * @brief Implementation of union find structure.
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
    /**
     * @brief construct union find object
     * @param[in] size: total number of nodes/elements/objects
     * **/
    union_find(const int size) : _size(size) {
        sets.reserve(size);
        parent.reserve(size);
        for (int i = 0; i < _size; i++) {
            sets.push_back(i);
            parent.push_back(i);
        }
    }

    /**
     * @brief return the size of the set
     *
     * @returns[int] returns the size of the set
     * **/
    int size() const {
        return _size;
    }

    /**
     * @brief determine the parent of a element
     *
     * @param[in] child: the item whose parent is to be determined
     * @returns[int] the parent of the child
     * **/
    int find_parent(int child) {
        if (parent[child] == child) return child;
        return find_parent(parent[child]);
    }

    /**
     * @brief merge/union two elements in a set.
     *
     * @param first, second: the items which should be merged into one subset.
     * Note that their parents or child are also merged into the same subset
     *
     * @returns[bool]: if the join was completed successfully or not.
     * If two elements have same parent, merge/union can not be performed
     * */
    bool join(const int first, const int second) {
        int first_parent = find_parent(first);
        int second_parent = find_parent(second);

        if (first_parent == second_parent) return false;
        int max_parent = std::max(first_parent, second_parent);
        int min_parent = std::min(first_parent, second_parent);

        std::replace(parent.begin(), parent.end(), min_parent, max_parent);
        return true;
    }

    /**
     * @brief Determine if two elements have the same parent of not.
     *
     * @param[in] first, second: two elements for which we determine if they have same parent or not
     * @returns[bool]: whether two input element have same parent or not
     * */
    bool has_same_parent(const int first, const int second) {
        return find_parent(first) == find_parent(second);
    }

    ~union_find() = default;
};


#endif //GRAPHS_UNIONFIND_H
