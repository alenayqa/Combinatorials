#pragma once
#include <iostream>
#include <math.h>

// https://e-maxx.ru/algo/segment_tree
using namespace std;

template <typename T>
class SegmentTree
{
private:
    T* tree;
    int _size;

    void build(T* arr, int ind, int l, int r);

    // indices of childs of vertex with index 'ind'
    int left(int ind) {return 2 * ind;}
    int right(int ind) {return 2 * ind + 1;}

    T recursive_sum(int ind, int l, int r, int part_l, int part_r);

public:
    SegmentTree(T* arr, int n);
    ~SegmentTree();

    T sum(int l, int r);
};

// int sum (int v, int tl, int tr, int l, int r) {
// 	if (l > r)
// 		return 0;
// 	if (l == tl && r == tr)
// 		return t[v];
// 	int tm = (tl + tr) / 2;
// 	return sum (v*2, tl, tm, l, min(r,tm))
// 		+ sum (v*2+1, tm+1, tr, max(l,tm+1), r);
// }

template <typename T>
T SegmentTree<T>::recursive_sum(int ind, int l, int r, int part_l, int part_r)
{
    // l, r - full subtree where the current vertex situated in
    // part_l, part_r - subborders in [l, r] where sum should be calculated
    // cout<<l<<' '<<r<<"||"<<part_l<<' '<<part_r<<endl;
    // if (part_l > part_r) return 0;
    if (l==part_l && r==part_r) return tree[ind];

    // divide current segment into 2 parts
    int middle = (l + r) / 2;

    int l_new_part_l = part_l;
    int l_new_part_r = min(middle, part_r);

    int r_new_part_l = max(part_l, middle + 1);
    int r_new_part_r = part_r;

    bool l_call = l_new_part_l <= l_new_part_r;
    bool r_call = r_new_part_l <= r_new_part_r;

    if (l_call && !r_call)
        return recursive_sum(left(ind), l, middle, l_new_part_l, l_new_part_r);

    if (!l_call && r_call)
        return recursive_sum(right(ind), middle + 1, r, r_new_part_l, r_new_part_r);

    return recursive_sum(left(ind), l, middle, l_new_part_l, l_new_part_r) +
           recursive_sum(right(ind), middle + 1, r, r_new_part_l, r_new_part_r);
}

template <typename T>
T SegmentTree<T>::sum(int l, int r)
{
    return recursive_sum(1, 0, _size - 1, l, r);
}

template <typename T>
void SegmentTree<T>::build(T* arr, int ind, int l, int r)
{
    // build the tree using array 'arr' at position 'ind' with borders [l, r]
    // if left border equals to right border then we don't need to calculate sum: this is a leaf of the tree

    if (l==r)
        tree[ind]=arr[l];
    else
    {
        // divide current segment into 2 parts
        int middle = (l + r) / 2;

        // build left and right subtree
        build(arr, left(ind), l, middle);
        build(arr, right(ind), middle + 1, r);

        // element at the current node is equal to the sum of elements of left and right subtrees
        tree[ind] = tree[left(ind)] + tree[right(ind)];
    }
}

template <typename T>
SegmentTree<T>::SegmentTree(T* arr, int n)
{
    tree = new T[4 * n];
    _size = n;
    build(arr, 1, 0, _size-1);
}

template <typename T>
SegmentTree<T>::~SegmentTree()
{
    delete[] tree;
}