#include <iostream>
#include <string>
#include "Trie.h"

using namespace std;


int main()
{
    Trie<int> t;
    t.add("six",6);
    t.add("four",4);
    t.add("one",1);
    t.add("", 0);
    t.add("hello!!!", 11);
    t.print();
    cout<<"SEARCH hello!!!:\n";
    int* res = t["hello!!!"];
    if (res)
        cout<<*res<<endl;
    else
        cout<<"no data\n";
    cout<<"REMOVE four:\n";
    t.remove("four");
    t.print();

}