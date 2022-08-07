#pragma once
#include <iostream>
#include <algorithm>
#include "Vertex.h"

using namespace std;

template<typename T>
class PriorityQueue
{
private:
    int volume;
    int _size;
    Vertex<T>* arr;
public:

    PriorityQueue(int _volume);
    ~PriorityQueue();

    bool add(T _value, int _priority);
    void remove_minimal();

    T* get_minimal();

};

template <typename T>
PriorityQueue<T>::PriorityQueue(int _volume = 5)
{
    volume = _volume;
    _size = 0;
    arr = new Vertex<T>[_volume];
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    delete[] arr;
}