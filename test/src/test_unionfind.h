#pragma once
#ifndef GRAPHS_TEST_UNIONFIND_H
#define GRAPHS_TEST_UNIONFIND_H

#include "gtest/gtest.h"
#include "../../src/unionfind.h"

TEST(unionfind, construct) {
    union_find union_find(10);
    union_find.join(0, 1);
    EXPECT_EQ(union_find.find_parent(0), union_find.find_parent(1));
    EXPECT_EQ(union_find.has_same_parent(1, 0), true);

    union_find.join(2, 3);
    EXPECT_EQ(union_find.find_parent(2), union_find.find_parent(3));
    EXPECT_EQ(union_find.has_same_parent(2, 3), true);

    union_find.join(4, 5);
    EXPECT_EQ(union_find.find_parent(4), union_find.find_parent(5));
    EXPECT_EQ(union_find.has_same_parent(4, 5), true);

    union_find.join(0, 4);
    EXPECT_EQ(union_find.find_parent(1), union_find.find_parent(5));
    EXPECT_EQ(union_find.has_same_parent(1, 5), true);
    EXPECT_EQ(union_find.has_same_parent(0, 5), true);
    EXPECT_EQ(union_find.has_same_parent(1, 4), true);
    EXPECT_EQ(union_find.has_same_parent(0, 4), true);
}

#endif //GRAPHS_TEST_UNIONFIND_H
