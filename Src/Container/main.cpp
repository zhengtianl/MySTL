#include <iostream>
#include "Vector.h"
using namespace MySTL;
using namespace std;
int main()
{
    Vector<string> vecs;
    vecs.push_back("hello");
    vecs.push_back("world");
    vecs.push_back("!");
    vecs.capacity();
    for(auto string1:vecs)
    {
        cout << string1 << endl;

    }
    cout << endl;
    cout << vecs.capacity();
}
