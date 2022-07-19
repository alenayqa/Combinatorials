#pragma once
#include "Trie.h"
#include "Vertex.h"
#include <string>
#include <iostream>

using namespace std;

template<class T>
Trie<T>::Trie()
{
    // Constructor. We need to have a root
    root = new Vertex<T>;
}

template<class T>
Trie<T>::~Trie()
{
    // Destructor. Delete root, another vertices will be removed in root-destructor (root as a Vertex)
    delete root;
}

template<class T>
void Trie<T>::add(string _key, T _data)
{
    if (_key.size()==0)
        return;

    // recursive search starts with first char of the key
    char start = _key[0];

    if (!root[start])
        root[start] = new Vertex<T>;

    // recursive search for place to add new value
    root[start].add(_key, _data.substr(1));
}

template<class T>
void Trie<T>::print()
{
    for (int i = 0; i<256; i++)
        root[i].print((char)i);
}

template<class T>
void A<T>::print()
{
    cout<<5.2<<endl;
}