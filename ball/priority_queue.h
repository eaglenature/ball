/*
 * <ball/priority_queue.h>
 *
 *  Created on: Sep 23, 2013
 *      Author: eaglenature@gmail.com
 */

#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <array>
#include <memory>

namespace ball
{


template<class Key,
         int NumElements,
         class Comparator = std::less<Key> >
class static_priority_queue
{
  public:
    explicit static_priority_queue()
        : N(0) {
    }

    void insert(Key key) {
        pq[++N] = key;
        swim(N);
    }

    Key top() {
        Key keyMax = pq[1];
        exch(1, N--);
        sink(1);
        return keyMax;
    }

    bool empty() const {
        return 0 == N;
    }

    int size() const {
        return N;
    }

  private:
    static_priority_queue(const static_priority_queue&) = delete;
    static_priority_queue& operator=(const static_priority_queue&) = delete;

    bool compare(int p, int q) const {
        return Comparator()(pq[p], pq[q]);
    }

    void exch(int p, int q) {
        Key k = pq[p];
        pq[p] = pq[q];
        pq[q] = k;
    }

    void swim(int k) {
        while (k > 1 && compare(k >> 1, k)) {
            exch(k, k >> 1);
            k = k >> 1;
        }
    }

    void sink(int k) {
        while ((k << 1) <= N) {
            int j = k << 1;
            if (j < N && compare(j, j+1)) ++j;
            if (!compare(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    std::array<Key, NumElements> pq;
    int N;
};



template<class Key,
         class Comparator = std::less<Key> >
class dynamic_priority_queue
{
  public:
    explicit dynamic_priority_queue(int capacity)
        : pq(new Key[capacity + 1])
        , length(capacity + 1)
        , N(0) {
    }

    void insert(Key key) {
        if (N >= length - 1) resize(length << 1);
        pq[++N] = key;
        swim(N);
    }

    Key top() {
        Key topKey = pq[1];
        exch(1, N--);
        sink(1);
        if ((N > 0) && (N == (length - 1) >> 2)) resize(length >> 1);
        return topKey;
    }

    bool empty() const {
        return 0 == N;
    }

    int size() const {
        return N;
    }

    int capacity() const {
        return length;
    }

  private:
    dynamic_priority_queue(const dynamic_priority_queue&) = delete;
    dynamic_priority_queue& operator=(const dynamic_priority_queue&) = delete;

    bool compare(int p, int q) const {
        return Comparator()(pq[p], pq[q]);
    }

    void exch(int p, int q) {
        Key k = pq[p];
        pq[p] = pq[q];
        pq[q] = k;
    }

    void swim(int k) {
        while (k > 1 && compare(k >> 1, k)) {
            exch(k, k >> 1);
            k = k >> 1;
        }
    }

    void sink(int k) {
        while ((k << 1) <= N) {
            int j = k << 1;
            if (j < N && compare(j, j+1)) ++j;
            if (!compare(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    void resize(int capacity) {
        if (capacity <= N) return;
        std::unique_ptr<Key[]> t(new Key[capacity]);
        for (auto i = 1; i <= N; ++i) t[i] = pq[i];
        pq.swap(t);
        length = capacity;
    }

    std::unique_ptr<Key[]> pq;
    int length;
    int N;
};

} // namespace ball

#endif /* PRIORITY_QUEUE_H_ */
