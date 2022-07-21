#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;


int main()
{
    Queue<int> q(5);
    q.push(1);
    q.push(5);
    q.push(1);
    q.push(7);
    q.push(32);
    q.print();
    cout<<"POP: "<<*q.pop()<<endl;
    q.print();
    cout<<"POP: "<<*q.pop()<<endl;
    q.print();
    cout<<"PUSH: "<<9<<endl;
    q.push(9);
    q.print();
    cout<<"POP EVERYTHING\n";
    for (int i = 0; i<4; i++)
        cout<<"POP: "<<*q.pop()<<endl;

}