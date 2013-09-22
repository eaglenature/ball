/*
 * SelectionSortTest.cpp
 *
 *  Created on: Sep 22, 2013
 *      Author: eaglenature@gmail.com
 */

#include <algorithm>
#include <random>
#include <gtest/gtest.h>

#include "../ball/selection_sort.h"


TEST(SelectionSort, IntegerKeys)
{
    typedef int Key;

    std::vector<Key> keys(2 << 10);
    std::generate(keys.begin(), keys.end(), [](){
        static Key item = 0;
        return item++;
    });

    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(keys.begin(), keys.end(), generator);

    ball::selection_sort(keys.begin(), keys.end());
    ASSERT_TRUE(std::is_sorted(keys.begin(), keys.end()));
}


TEST(SelectionSort, StringKeys)
{
    typedef std::string Key;
    std::vector<Key> keys(6);

    std::generate(keys.begin(), keys.end(), [](){
        static const std::vector<std::string> cities =
        {"New York", "Tokyo", "Rome", "Oslo", "Ankara", "London", "Paris"};
        static int item = 0;
        return cities[item++ % cities.size()];
    });

    ball::selection_sort(keys.begin(), keys.end());
    ASSERT_TRUE(std::is_sorted(keys.begin(), keys.end()));
}
