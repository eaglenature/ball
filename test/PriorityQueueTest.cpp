/*
 * PriorityQueueTest.cpp
 *
 *  Created on: Sep 23, 2013
 *      Author: eaglenature@gmail.com
 */

#include <gtest/gtest.h>
#include "../ball/priority_queue.h"


TEST(StaticMaxPriorityQueue, Empty)
{
    ball::static_priority_queue<int, 10, std::less<int> > pq;
    ASSERT_TRUE(pq.empty());

    pq.insert(3);
    ASSERT_FALSE(pq.empty());
}

TEST(StaticMaxPriorityQueue, Insert)
{
    ball::static_priority_queue<int, 10, std::less<int> > pq;

    pq.insert(3);
    pq.insert(7);
    pq.insert(1);
    pq.insert(5);

    ASSERT_EQ(7, pq.top());
    ASSERT_EQ(5, pq.top());
    ASSERT_EQ(3, pq.top());
    ASSERT_EQ(1, pq.top());
    ASSERT_TRUE(pq.empty());
}

TEST(StaticMinPriorityQueue, Empty)
{
    ball::static_priority_queue<int, 10, std::greater<int> > pq;
    ASSERT_TRUE(pq.empty());

    pq.insert(3);
    ASSERT_FALSE(pq.empty());
}

TEST(StaticMinPriorityQueue, Insert)
{
    ball::static_priority_queue<int, 10, std::greater<int> > pq;

    pq.insert(3);
    pq.insert(7);
    pq.insert(1);
    pq.insert(5);

    ASSERT_EQ(1, pq.top());
    ASSERT_EQ(3, pq.top());
    ASSERT_EQ(5, pq.top());
    ASSERT_EQ(7, pq.top());
    ASSERT_TRUE(pq.empty());
}



TEST(DynamicMaxPriorityQueue, Empty)
{
    ball::dynamic_priority_queue<int, std::less<int> > pq(10);
    ASSERT_TRUE(pq.empty());

    pq.insert(3);
    ASSERT_FALSE(pq.empty());
}

TEST(DynamicMaxPriorityQueue, Capacity)
{
    ball::dynamic_priority_queue<int, std::less<int> > pq(2);

    ASSERT_EQ(0, pq.size());
    ASSERT_EQ(3, pq.capacity());

    pq.insert(3);
    ASSERT_EQ(1, pq.size());
    ASSERT_EQ(3, pq.capacity());

    pq.insert(7);
    ASSERT_EQ(2, pq.size());
    ASSERT_EQ(3, pq.capacity());

    pq.insert(1);
    ASSERT_EQ(3, pq.size());
    ASSERT_EQ(6, pq.capacity());

    pq.insert(5);
    ASSERT_EQ(4, pq.size());
    ASSERT_EQ(6, pq.capacity());

    ASSERT_EQ(7, pq.top());
    ASSERT_EQ(3, pq.size());
    ASSERT_EQ(6, pq.capacity());

    ASSERT_EQ(5, pq.top());
    ASSERT_EQ(2, pq.size());
    ASSERT_EQ(6, pq.capacity());

    ASSERT_EQ(3, pq.top());
    ASSERT_EQ(1, pq.size());
    ASSERT_EQ(3, pq.capacity());

    ASSERT_EQ(1, pq.top());
    ASSERT_EQ(0, pq.size());
    ASSERT_EQ(3, pq.capacity());

    ASSERT_TRUE(pq.empty());
}
