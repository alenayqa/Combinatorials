#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;


int main()
{
    PriorityQueue<int> q;
    q.add(1,50);
    q.add(3,7);
    q.add(2,6);
    q.add(4,20);
    q.print();
    cout<<*q.get_minimal()<<endl;

}