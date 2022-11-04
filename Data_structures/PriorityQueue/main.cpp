#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

#define PRINT_Q "1"
#define ADD_Q "2"
#define TOP_Q "3"
#define POP_Q "4"

void add_element(PriorityQueue<int>& q)
{
    int value, priority;
    std::cout<<"Добавить число: ";
    std::cin>>value;
    std::cout<<"Приоритет числа: ";
    std::cin>>priority;
    q.push(value, priority);
}


int main()
{
    PriorityQueue<int> q(1);

    while (true)
    {
        std::cout<<"\nДействие\n";
        std::cout<<PRINT_Q<<" - напечатать очередь\n";
        std::cout<<ADD_Q<<" - добавить элемент\n";
        std::cout<<TOP_Q<<" - посмотреть элемент с минимальным приоритетом\n";
        std::cout<<POP_Q<<" - удалить верхний элемент с минимальным приоритетом\n";
        std::cout<<"Другое - выйти\n";

        std::string action;
        std::cin>>action;

        if (action == PRINT_Q)
        {
            q.print();
        }
        else if (action == ADD_Q)
        {
            add_element(q);
        }
        else if (action == TOP_Q)
        {
            std::cout<<"Минимальный приоритет у числа: " <<q.top()<<std::endl;
        }
        else if (action == POP_Q)
        {
            std::cout<<"Удален элемент: "<<q.pop()<<std::endl;
        }
        else
        {
            break;
        }

    }
}