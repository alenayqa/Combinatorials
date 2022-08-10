#pragma once
#include <iostream>

// https://e-maxx.ru/algo/segment_tree

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

public:
    SegmentTree(T* arr = nullptr, int n = 0);
    ~SegmentTree();
};

template <typename T>
void SegmentTree<T>::build(T* arr, int ind, int l, int r)
{
    // build the tree using array 'arr' at position 'ind' with borders [l, r]
    // if left border equals to right border then we don't need to calculate sum: this is a leaf of the tree
    if (l==r)
        tree[ind]=a[l];
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
SegmentTree<T>::SegmentTree(T* arr, int n)
{
    delete[] tree;
}