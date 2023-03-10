#include <iostream>
#include "myString.h"
using namespace MySTL;
using namespace std;
int main() {
    myString<char> s2("Hello, world!");
    myString<char> s1;
    s1 = "hello, world!";// 创建一个包含字符串 "Hello, world!" 的 myString 对象
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << (s1 + s2)<< endl;
}
