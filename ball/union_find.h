/*
 * <ball/union_find.h>
 *
 *  Created on: Sep 22, 2013
 *      Author: eaglenature@gmail.com
 */

#ifndef UNION_FIND_H_
#define UNION_FIND_H_

#include <memory>


namespace ball
{

class quick_find
{
  public:
    explicit quick_find(int n)
        : index(new int[n])
        , counter(n)
        , size(n) {

        for (auto i = 0; i < size; ++i)
            index[i] = i;
    }

    int count() const {
        return counter;
    }

    int find(int p) const {
        return index[p];
    }

    bool connected(int p, int q) const {
        return index[p] == index[q];
    }

    void connect(int p, int q) {
        if (connected(p, q))
            return;
        int pid = index[p];
        int qid = index[q];
        for (auto i = 0; i < size; ++i)
            if (index[i] == pid)
                index[i] = qid;
        --counter;
    }

  private:
    quick_find(const quick_find&) = delete;
    quick_find& operator=(const quick_find&) = delete;

    std::unique_ptr<int[]> index;
    int counter;
    const int size;
};


class quick_union
{
  public:
    explicit quick_union(int n)
        : index(new int[n])
        , counter(n)
        , size(n) {

        for (auto i = 0; i < size; ++i)
            index[i] = i;
    }

    int count() const {
        return counter;
    }

    bool connected(int p, int q) const {
        return root(p) == root(q);
    }

    void connect(int p, int q) {
        int rp = root(p);
        int rq = root(q);
        if (rp == rq) return;
        index[rp] = rq;
        --counter;
    }

  private:
    quick_union(const quick_union&) = delete;
    quick_union& operator=(const quick_union&) = delete;

    int root(int p) const {
        while (p != index[p])
            p = index[p];
        return p;
    }

    std::unique_ptr<int[]> index;
    int counter;
    const int size;
};



class weighted_quick_union
{
  public:
    explicit weighted_quick_union(int n)
        : index(new int[n])
        , weight(new int[n])
        , counter(n)
        , size(n) {

        for (auto i = 0; i < size; ++i)
            index[i] = i;

        for (auto i = 0; i < size; ++i)
            weight[i] = 1;
    }

    int count() const {
        return counter;
    }

    bool connected(int p, int q) const {
        return root(p) == root(q);
    }

    void connect(int p, int q) {
        int rp = root(p);
        int rq = root(q);
        if (rp == rq) return;
        if (weight[rp] < weight[rq]) {
            index[rp] = rq;
            weight[rq] += weight[rp];
        } else {
            index[rq] = rp;
            weight[rp] += weight[rq];
        }
        --counter;
    }

  private:
    weighted_quick_union(const weighted_quick_union&) = delete;
    weighted_quick_union& operator=(const weighted_quick_union&) = delete;

    int root(int p) const {
        while (p != index[p])
            p = index[p];
        return p;
    }

    std::unique_ptr<int[]> index;
    std::unique_ptr<int[]> weight;
    int counter;
    const int size;
};



class weighted_quick_union_pc
{
  public:
    explicit weighted_quick_union_pc(int n)
        : index(new int[n])
        , weight(new int[n])
        , counter(n)
        , size(n) {

        for (auto i = 0; i < size; ++i)
            index[i] = i;

        for (auto i = 0; i < size; ++i)
            weight[i] = 1;
    }

    int count() const {
        return counter;
    }

    bool connected(int p, int q) const {
        return root(p) == root(q);
    }

    void connect(int p, int q) {
        int rp = root(p);
        int rq = root(q);
        if (rp == rq) return;
        if (weight[rp] < weight[rq]) {
            index[rp] = rq;
            weight[rq] += weight[rp];
        } else {
            index[rq] = rp;
            weight[rp] += weight[rq];
        }
        --counter;
    }

  private:
    weighted_quick_union_pc(const weighted_quick_union_pc&) = delete;
    weighted_quick_union_pc& operator=(const weighted_quick_union_pc&) = delete;

    int root(int p) const {
        while (p != index[p]) {
            index[p] = index[index[p]];
            p = index[p];
        }
        return p;
    }

    std::unique_ptr<int[]> index;
    std::unique_ptr<int[]> weight;
    int counter;
    const int size;
};

} // namespace ball

#endif /* UNION_FIND_H_ */
