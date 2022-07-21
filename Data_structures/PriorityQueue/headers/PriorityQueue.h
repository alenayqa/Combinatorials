#pragma once
#include <iostream>

using namespace std;

template<typename T>
class PriorityQueue
{
private:

public:

    PriorityQueue();
    ~PriorityQueue();

    bool add(T _value, int _priority);
    void remove_minimal();

    T* get_minimal();

};