#pragma once
#include <string>

using namespace std;

template<typename T>
class Trie
{
private:
    Vertex<T>* root;

public:
    Trie();
    ~Trie();

    // add a new value using a key
    void add(string _key, T _data);

    // remove value using a key
    void remove(string _key);

    // find value using a key
    T* operator[] (string _key);
};