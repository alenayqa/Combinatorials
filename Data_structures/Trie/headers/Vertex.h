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

    void print(string _key);

    ~Vertex();
};


template<typename T>
Vertex<T>* Vertex<T>::operator[] (int index)
{
    return childs[index];
}


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