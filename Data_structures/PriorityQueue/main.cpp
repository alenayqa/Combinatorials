#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;


int main()
{
    PriorityQueue<int> q(1);
    q.push(1,50);
    q.push(3,7);
    q.push(2,6);
    q.push(4,20);
    q.print();
    while (q.size()>0)
    {
        cout<<q.pop()<<endl;
    }
    

}