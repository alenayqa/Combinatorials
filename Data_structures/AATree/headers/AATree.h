#pragma once
#include <iostream>
#include "Vertex.h"

using namespace std;

template <typename K, typename D>
class AATree
{
private:
    Vertex<K, D>* root = nullptr;
public:
    void add(K _key, D _data);
    void remove(K _key);
    
    D* find(K _key);

    ~AATree<K,D>();
};

template <typename K, typename D>
AATree<K, D>::~AATree()
{
    if (root) delete root;
}