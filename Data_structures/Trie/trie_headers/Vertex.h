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

    ~Vertex();
};