/*
 * UnionFindTest.cpp
 *
 *  Created on: Sep 22, 2013
 *      Author: eaglenature@gmail.com
 */

#include <algorithm>
#include <random>
#include <gtest/gtest.h>

#include "../ball/union_find.h"


TEST(QuickFind, Count)
{
    ball::quick_find qf(10);
    ASSERT_EQ(10, qf.count());
    qf.connect(1, 4);
    ASSERT_EQ(9, qf.count());
}
TEST(QuickFind, Find)
{
    ball::quick_find qf(10);
    ASSERT_EQ(0, qf.find(0));
    ASSERT_EQ(5, qf.find(5));
    ASSERT_EQ(9, qf.find(9));
}
TEST(QuickFind, Connected)
{
    ball::quick_find qf(10);
    ASSERT_FALSE(qf.connected(0, 1));
    ASSERT_FALSE(qf.connected(8, 9));
}
TEST(QuickFind, Connect)
{
    ball::quick_find qf(10);
    qf.connect(0, 1);
    ASSERT_TRUE(qf.connected(0, 1));
    qf.connect(1, 4);
    ASSERT_TRUE(qf.connected(1, 4));
    ASSERT_TRUE(qf.connected(0, 4));
    qf.connect(6, 9);
    ASSERT_TRUE(qf.connected(6, 9));
    qf.connect(5, 6);
    ASSERT_TRUE(qf.connected(5, 6));
    ASSERT_TRUE(qf.connected(5, 9));
}



TEST(QuickUnion, Count)
{
    ball::quick_union qu(10);
    ASSERT_EQ(10, qu.count());
    qu.connect(1, 4);
    ASSERT_EQ(9, qu.count());
}
TEST(QuickUnion, Connected)
{
    ball::quick_union qu(10);
    ASSERT_FALSE(qu.connected(0, 1));
    ASSERT_FALSE(qu.connected(8, 9));
}
TEST(QuickUnion, Connect)
{
    ball::quick_union qu(10);
    qu.connect(0, 1);
    ASSERT_TRUE(qu.connected(0, 1));
    qu.connect(1, 4);
    ASSERT_TRUE(qu.connected(1, 4));
    ASSERT_TRUE(qu.connected(0, 4));
    qu.connect(6, 9);
    ASSERT_TRUE(qu.connected(6, 9));
    qu.connect(5, 6);
    ASSERT_TRUE(qu.connected(5, 6));
    ASSERT_TRUE(qu.connected(5, 9));
}



TEST(WeightedQuickUnion, Count)
{
    ball::weighted_quick_union wqu(10);
    ASSERT_EQ(10, wqu.count());
    wqu.connect(1, 4);
    ASSERT_EQ(9, wqu.count());
}
TEST(WeightedQuickUnion, Connected)
{
    ball::weighted_quick_union wqu(10);
    ASSERT_FALSE(wqu.connected(0, 1));
    ASSERT_FALSE(wqu.connected(8, 9));
}
TEST(WeightedQuickUnion, Connect)
{
    ball::weighted_quick_union wqu(10);
    wqu.connect(0, 1);
    ASSERT_TRUE(wqu.connected(0, 1));
    wqu.connect(1, 4);
    ASSERT_TRUE(wqu.connected(1, 4));
    ASSERT_TRUE(wqu.connected(0, 4));
    wqu.connect(6, 9);
    ASSERT_TRUE(wqu.connected(6, 9));
    wqu.connect(5, 6);
    ASSERT_TRUE(wqu.connected(5, 6));
    ASSERT_TRUE(wqu.connected(5, 9));
}



TEST(WeightedQuickUnionPathCompression, Count)
{
    ball::weighted_quick_union_pc wqupc(10);
    ASSERT_EQ(10, wqupc.count());
    wqupc.connect(1, 4);
    ASSERT_EQ(9, wqupc.count());
}
TEST(WeightedQuickUnionPathCompression, Connected)
{
    ball::weighted_quick_union_pc wqupc(10);
    ASSERT_FALSE(wqupc.connected(0, 1));
    ASSERT_FALSE(wqupc.connected(8, 9));
}
TEST(WeightedQuickUnionPathCompression, Connect)
{
    ball::weighted_quick_union_pc wqupc(10);
    wqupc.connect(0, 1);
    ASSERT_TRUE(wqupc.connected(0, 1));
    wqupc.connect(1, 4);
    ASSERT_TRUE(wqupc.connected(1, 4));
    ASSERT_TRUE(wqupc.connected(0, 4));
    wqupc.connect(6, 9);
    ASSERT_TRUE(wqupc.connected(6, 9));
    wqupc.connect(5, 6);
    ASSERT_TRUE(wqupc.connected(5, 6));
    ASSERT_TRUE(wqupc.connected(5, 9));
}
