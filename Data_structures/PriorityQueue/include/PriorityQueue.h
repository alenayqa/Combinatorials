#pragma once
#include <iostream>
#include <algorithm>
#include <memory>
#include <stdexcept>
#include "Vertex.h"

// https://dementiy.gitbooks.io/algo/content/heaps.html

template<typename T>
class PriorityQueue
{
private:
    int m_volume;
    int m_size;
    std::unique_ptr<Vertex<T>[]> m_arr;

    void swap(int ind1, int ind2);

    int parent(int i) { return (i-1) / 2;}
    int left(int i) { return 2*i + 1;}
    int right(int i) { return 2*i + 2;}

    void heapify_down(int ind);
    void heapify_up(int ind);

public:

    PriorityQueue(int volume=5);

    void push(T value, int priority);
    T pop();
    T top();

    int size();

    void print();

};

/**
 * Создает очередь с приоритетом
 * @param volume зарезервированный объем очереди. НЕ является 
 * максимальным объемом. При переполнении объем перевыделяется автоматически
*/
template <typename T>
PriorityQueue<T>::PriorityQueue(int volume)
{
    m_volume = volume;
    m_size = 0;
    m_arr = std::make_unique<Vertex<T>[]>(volume);
}

/**
 * Получить элемент с минимальным приоритетом.
 * Этот элемент удаляется из очереди
*/
template <typename T>
T PriorityQueue<T>::pop()
{
    if (m_size==0)
    {
        throw std::out_of_range("EMPTY QUEUE");
    }
    T ret = m_arr[0].data;

    // Заменяем голову на самый правый элемент
    swap(0, m_size - 1);
    m_size--;

    // Балансируем дерево
    heapify_down(0);
    return ret;
}

/**
 * Получить элемент с минимальным приоритетом.
 * Этот элемент не удаляется из очереди
*/
template <typename T>
T PriorityQueue<T>::top()
{
    return m_arr[0].data;
}

/**
 * Добавляет число в очередь
 * @param value добавляемое значение
 * @param priority приоритет добавляемого значения
*/
template <typename T>
void PriorityQueue<T>::push(T value, int priority)
{
    // Если место закончилось, то перевыделяем память
    if (m_size >= m_volume)
    {
        m_volume *= 2;

        std::unique_ptr<Vertex<T>[]> tmp = std::make_unique<Vertex<T>[]>(m_volume);
        for (int i = 0; i < m_size; i++)
        {
            tmp[i] = m_arr[i];
        }
        std::swap(tmp, m_arr);
    }

    // Дописываем в конец массива новое значение
    m_arr[m_size] = Vertex<T>(value, priority);

    // Балансируем дерево
    heapify_up(m_size);
    m_size++;
}

/**
 * Напечатать содержимое очереди
*/
template <typename T>
void PriorityQueue<T>::print()
{
    if (m_size > 0)
    {
        for (int i = 0; i<m_size; i++)
            std::cout<<m_arr[i].data <<" : "<<m_arr[i].priority<<std::endl;
    }
    else
    {
        std::cout<<"Очередь пуста\n";
    }
}

/**
 * Возвращает размер очереди
*/
template <typename T>
int PriorityQueue<T>::size()
{
    return m_size;
}

template <typename T>
void PriorityQueue<T>::heapify_up(int ind)
{
    while (ind > 0 && m_arr[parent(ind)].priority >= m_arr[ind].priority)
    {
        swap(ind, parent(ind));
        ind = parent(ind);
    }
}

template <typename T>
void PriorityQueue<T>::heapify_down(int ind)
{
    int r = right(ind);
    int l = left(ind);

    // Ищем минимальный элемент среди
    // --- ind
    // --- right(ind)
    // --- left(ind)

    int minInd = ind;
    if (l < m_size && m_arr[l].priority < m_arr[minInd].priority)
        minInd = l;
    if (r < m_size && m_arr[r].priority < m_arr[minInd].priority)
        minInd = r;

    // Если дерево не сбалансировано, то меняем ind с minInd и продолжаем балансировку рекурсивно 
    if (ind != minInd)
    {
        swap(ind, minInd);
        heapify_down(minInd);
    } 
}

template <typename T>
void PriorityQueue<T>::swap(int ind1, int ind2)
{
    Vertex<T> tmp = m_arr[ind1];
    m_arr[ind1] = m_arr[ind2];
    m_arr[ind2] = tmp;
}


