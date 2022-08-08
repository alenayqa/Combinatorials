#pragma once
#include <iostream>
#include <algorithm>
#include "Vertex.h"

// https://dementiy.gitbooks.io/algo/content/heaps.html

using namespace std;

template<typename T>
class PriorityQueue
{
private:
    int volume;
    int _size;
    Vertex<T>** arr;

    void swap(int ind1, int ind2);

    int parent(int i) { return (i-1) / 2;}
    int left(int i) { return 2*i + 1;}
    int right(int i) { return 2*i + 2;}

    void balance(int ind);

public:

    PriorityQueue(int _volume);
    ~PriorityQueue();

    bool add(T _value, int _priority);
    void remove(T _value);

    T* get_minimal();

};

template <typename T>
void PriorityQueue<T>::balance(int ind)
{
    int r = right(ind);
    int l = left(ind);

    // find minimal element in:
    // --- ind
    // --- right(ind)
    // --- left(ind)

    int minInd = ind;
    if (l < _size && arr[l]->priority < arr[minInd]->priority)
        minInd = l;
    if (r < _size && arr[r]->priority < arr[minInd]->priority)
        minInd = r;

    // if tree isn't balanced then swap ind with minInd and balance child
    if (ind != minInd)
    {
        swap(ind, minInd);
        balance(minInd);
    } 
}

template <typename T>
T* PriorityQueue<T>::get_minimal()
{
    if (arr[0])
        return &arr[0].data;
    else return nullptr;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int _volume = 5)
{
    volume = _volume;
    _size = 0;
    arr = new Vertex<T>*[_volume];
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    for (int i = 0; i<volume; i++)
        delete arr[i];
    delete[] arr;
}
template <typename T>
void PriorityQueue<T>::swap(int ind1, int ind2)
{
    T* tmp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = tmp;
}
