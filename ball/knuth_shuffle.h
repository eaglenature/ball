/*
 * <ball/knuth_shuffle.h>
 *
 *  Created on: Sep 22, 2013
 *      Author: eaglenature@gmail.com
 */

#ifndef KNUTH_SHUFFLE_H_
#define KNUTH_SHUFFLE_H_

#include <cstdlib>


namespace ball
{

template<class InputIterator>
void knuth_shuffle(InputIterator first, InputIterator last)
{
    auto distance = std::distance(first, last);
    for (auto curr = 0; curr < distance; ++curr)
    {
        std::swap(first[std::rand() % (curr + 1)], first[curr]);
    }
}

} // namespace ball

#endif /* KNUTH_SHUFFLE_H_ */
