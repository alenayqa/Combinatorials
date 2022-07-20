#pragma once
using namespace std;

template<typename T>
class Queue
{
private:
    T* data;
    int volume;
    int head = -1;
    int tail = -1;

    bool isEmpty();

public:
    Queue(int _volume);
    ~Queue();

    int size();
    void push(T _value);

    T* pop();
}; 

template<typename T>
Queue<T>::Queue(int _volume)
{
    volume = _volume;
    data = new T[volume];
}

template<typename T>
Queue<T>::~Queue()
{
    delete data;
}

