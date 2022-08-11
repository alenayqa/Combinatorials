#pragma once
#include <iostream>

template <typename T>
class Vertex
{
public:
    T data;
    int level;

    Vertex<T>* l = nullptr;
    Vertex<T>* r = nullptr;

    Vertex<T>(T _data, int _level, Vertex<T>* _l, Vertex<T>* _r);
    ~Vertex<T>();
};

template <typename T>
Vertex<T>::Vertex(T _data, int _level, Vertex<T>* _l, Vertex<T>* _r)
{
    l = _l;
    r = _r;
    level = _level;
    data = _data;
}

template <typename T>
Vertex<T>::~Vertex()
{
    delete l; delete r;
}