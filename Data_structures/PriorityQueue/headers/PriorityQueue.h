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

public:

    PriorityQueue(int _volume);
    ~PriorityQueue();

    bool add(T _value, int _priority);
    void remove_minimal();

    T* get_minimal();

};

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
