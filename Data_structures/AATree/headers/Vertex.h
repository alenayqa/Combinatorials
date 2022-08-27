#pragma once
#include <iostream>

template <typename K, typename D>
class Vertex
{
public:
    K key;
    D data;
    int level;

    Vertex<K, D>* l = nullptr;
    Vertex<K, D>* r = nullptr;

    Vertex<K, D>(K _key, D _data, int _level, Vertex<K, D>* _l, Vertex<K, D>* _r);
    ~Vertex<K, D>();
};

template <typename K, typename D>
Vertex<K, D>::Vertex(K _key, D _data, int _level, Vertex<K, D>* _l = nullptr, Vertex<K, D>* _r = nullptr)
{
    l = _l;
    r = _r;
    level = _level;
    data = _data;
}

template <typename K, typename D>
Vertex<K, D>::~Vertex()
{
    delete l; delete r;
}