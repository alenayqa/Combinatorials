#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
    T* data;
    int volume;
    int _size = 0;

    // head points to the place where first element of the queue is situated in
    int head = 0;

    // tail points to the place where next element has to be inserted to
    int tail = 0;

    bool isEmpty();

public:
    Queue(int _volume);
    ~Queue();

    int size();
    bool push(T _value);

    T* pop();

    void print();
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

template<typename T>
bool Queue<T>::isEmpty()
{
    return _size == 0;
}

template<typename T>
int Queue<T>::size()
{
    return _size;
}

template<typename T>
bool Queue<T>::push(T _value)
{
    // if queue is already full then we do not push new value
    if (size() >= volume)
        return false;

    // new value is inserted to the place tail points to
    data[tail] = _value;

    // tail moves to the next position around
    tail = (tail + 1) % volume;
    _size++;
    return true;
}

template<typename T>
T* Queue<T>::pop()
{
    // we can't return value if the queue is empty
    if (isEmpty())
        return nullptr;

    // take the value head points to
    T& ret = data[head];
    // head moves to the next position around
    head = (head + 1) % volume;
    _size--;
    return &ret;
}

template<typename T>
void Queue<T>::print()
{
    for (int i = 0; i < size(); i++)
    {
        cout<<data[(head + i) % volume]<<' ';
    }
    cout<<endl;
}
