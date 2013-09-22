/*
 * <ball/insertion_sort.h>
 *
 *  Created on: Sep 22, 2013
 *      Author: eaglenature@gmail.com
 */

#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_


namespace ball
{

template<class InputIterator>
void insertion_sort(InputIterator first, InputIterator last)
{
    typedef typename std::iterator_traits<InputIterator>::value_type value_type;
    auto distance = std::distance(first, last);
    for (auto curr = 0; curr < distance; ++curr)
    {
        auto k = curr;
        while (k > 0 && std::less<value_type>()(first[k], first[k-1]))
        {
            std::swap(first[k], first[k-1]);
            --k;
        }
    }
}

} // namespace ball

#endif /* INSERTION_SORT_H_ */
