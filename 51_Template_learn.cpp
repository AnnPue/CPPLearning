#include <iostream>
#include <string>
using namespace std;

template <typename T>

T MAX(T a, T b)
{
    return a > b ? a : b;
}
int main()
{
    int i = 9, j = 10;
    cout << MAX(i, j) << endl;
    double x = 3.14, y = 2.718;
    cout << MAX(x, y) << endl;
    string s1 = "Hello", s2 = "World";
    cout << MAX(s1, s2) << endl;
}