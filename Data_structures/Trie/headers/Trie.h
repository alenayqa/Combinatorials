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
    T& operator[] (string _key);

    void print();
};

template<typename T>
class A
{
    public:
    T s=5;
    void print();
};

// template<typename T>
// void A<T>::print()
// {
//     cout<<5.2<<endl;
// }

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

template<typename T>
void A<T>::print()
{
    cout<<5.2<<endl;
}