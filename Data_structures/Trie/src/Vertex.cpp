#include "../trie_headers/Vertex.h"

using namespace std;

template<typename T>
Vertex<T>::~Vertex()
{
    // Delete all childs of the vertex
    for (int i=0; i<256; i++)
    {
        if (childs[i]!=nullptr)
            delete childs[i];
    }
}