#pragma once
#include "Vertex.h"
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class Trie
{
private:
    Vertex<T> *root;

public:
    Trie();
    ~Trie();

    // add a new value using a key
    void add(string _key, T _data);

    // remove value using a key
    void remove(string _key);

    // find value using a key
    T* operator[] (string _key);

    void print();
};

template<typename T>
Trie<T>::Trie()
{
    // Constructor. We need to have a root
    root = new Vertex<T>;
}

template<typename T>
Trie<T>::~Trie()
{
    // Destructor. Delete root, another vertices will be removed in root-destructor (root as a Vertex)
    delete root;
}

template<typename T>
void Trie<T>::add(string _key, T _data)
{
    if (_key.size()==0)
    {
        root->data = _data;
        root->hasAData = true;
        return;
    }

    // recursive search starts with first char of the key
    char start = _key[0];

    if (!root->childs[start])
        root->childs[start] = new Vertex<T>;

    // recursive search for place to add new value
    root->childs[start]->add(_key.substr(1), _data);
}

template<typename T>
T* Trie<T>::operator[] (string _key)
{
    if (_key.size()==0)
        if (root->hasAData)
            return &root->data;
        else
            return nullptr;
    
    char start = _key[0];

    // if we do not have next subtree starting with the first char of the key then there is not out value
    if (!root->childs[start])
        return nullptr;
        
    // recursive search for a value with the key
    return root->childs[start]->find(_key.substr(1));
}

template<typename T>
void Trie<T>::print()
{
    if (root->hasAData)
    {
        cout<<" : "<<root->data<<endl;
    }
    for (int i = 0; i<256; i++)
        if (root->childs[i])
            root->childs[i]->print(string(1, (char)i));
}
