/*
 * KnuthShuffleTest.cpp
 *
 *  Created on: Sep 22, 2013
 *      Author: eaglenature@gmail.com
 */

#include <ostream>
#include <algorithm>
#include <gtest/gtest.h>

#include "../ball/knuth_shuffle.h"


TEST(KnuthShuffle, IntegerKeys)
{
    std::srand(std::time(0));

    typedef int Key;
    std::vector<Key> keys(15);

    std::generate(keys.begin(), keys.end(), [](){
        static Key item = 0;
        return item++;
    });

    ball::knuth_shuffle(keys.begin(), keys.end());

    //std::cout << "{ ";
    //std::copy(keys.begin(), keys.end(), std::ostream_iterator<Key>(std::cout, " "));
    //std::cout << " }\n";
}


TEST(KnuthShuffle, StringKeys)
{
    std::srand(std::time(0));

    typedef std::string Key;
    std::vector<Key> keys(6);

    std::generate(keys.begin(), keys.end(), [](){
        static const std::vector<std::string> cities =
        {"New York", "Tokyo", "Rome", "Oslo", "London", "Paris"};
        static int item = 0;
        return cities[item++ % cities.size()];
    });

    ball::knuth_shuffle(keys.begin(), keys.end());

    //std::cout << "{ ";
    //std::copy(keys.begin(), keys.end(), std::ostream_iterator<Key>(std::cout, " "));
    //std::cout << " }\n";
}
