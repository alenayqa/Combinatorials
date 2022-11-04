#pragma once

#include <iostream>

template <typename T>
struct Vertex
{
    T data;
    int priority;

    Vertex(){}
    Vertex(T _data, int _priority)
    {
        data = _data;
        priority = _priority;
    }
};