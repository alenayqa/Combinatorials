#pragma once
#include <string>

using namespace std;

template<typename T>
struct Vertex
{
    // Value which has to be saved
    T data;

    // Marker to show if the vertex contains data
    bool hasAData = false;

    // List of vertices coming from this vertex
    Vertex<T>* childs[255];
};

template<typename T>
class Trie
{
private:
    Vertex<T>* root;
    
public:
    Trie(){root = new Vertex<T>;}

    // add a new value using a key
    void add(string _key, T _data);

    // remove value using a key
    void remove(string _key);

    // find value using a key
    T* operator[] (string _key);
};