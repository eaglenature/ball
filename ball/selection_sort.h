/*
 * <ball/selection_sort.h>
 *
 *  Created on: Sep 22, 2013
 *      Author: eaglenature@gmail.com
 */

#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_


namespace ball
{

template<class InputIterator>
void selection_sort(InputIterator first, InputIterator last)
{
    typedef typename std::iterator_traits<InputIterator>::value_type value_type;
    auto distance = std::distance(first, last);
    for (auto curr = 0; curr < distance; ++curr)
    {
        auto minimal = curr;
        for (auto i = curr + 1; i < distance; ++i)
            if (std::less<value_type>()(first[i], first[minimal]))
                minimal = i;
        std::swap(first[curr], first[minimal]);
    }
}

} // namespace ball

#endif /* SELECTION_SORT_H_ */
