#include <iostream>
#include <string>
#include "SegmentTree.h"

using namespace std;


int main()
{
    int n = 10;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    SegmentTree<int> t(a, n);
    cout<<t.sum(0,4)<<endl;
    cout<<t.sum(6,9)<<endl;

    

}