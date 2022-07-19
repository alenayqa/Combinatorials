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
    Vertex<T>* childs[256];

    Vertex<T>* operator[] (int index);

    void add(string _key, T _data);

    T* find(string _key);

    void print(string _key);

    ~Vertex();
};


template<typename T>
Vertex<T>::~Vertex()
{
    // Delete all childs of the vertex
    for (int i=0; i<256; i++)
    {
        if (childs[i])
            delete childs[i];
    }
}

template<typename T>
void Vertex<T>::add(string _key, T _data)
{
    // if key has no more chars then we came to the correct place
    if (_key.size()==0)
    {
        data = _data;
        hasAData = true;
        return;
    }

    // else we need to continue search starting with the 
    // vertex corresponting to the first char of the key
    char start = _key[0];
    if (!childs[start])
        childs[start] = new Vertex<T>;
    
    childs[start]->add(_key.substr(1), _data);
}

template<typename T>
void Vertex<T>::print(string _key)
{

    if (hasAData)
        cout<<_key<<" : "<<data<<endl;
        
    for (int i = 0; i<256; i++)
        if (childs[i])
            childs[i]->print(_key+(char)i);
}

template<typename T>
T* Vertex<T>::find(string _key)
{
    // if the remained part of key is empty then we found the value
    if (_key.size()==0)
        return &data;

    // recursive search starts with first char in the key
    char start = _key[0];

    // if we do not have next subtree starting with the first char of the key then there is not out value
    if (!childs[start])
        return nullptr;
    return childs[start]->find(_key.substr(1));
}
