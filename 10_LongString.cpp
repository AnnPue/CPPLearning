/*
noob58 无限长正整数排列字符串

定义无限字符串 S="123456789101112......" ，即 将所有正整数依次拼接得到。
珂朵莉想知道该字符串的第 n 个字符是什么。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i) s += to_string(i);
    cout << s[n - 1];
}