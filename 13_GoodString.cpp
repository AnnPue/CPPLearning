/*
牛牛喜欢跟字符串玩耍，他学会了一种新操作：在当前字符串中任意位置（包括开头和结尾）插入子串 ab。

牛牛称一个字符串为 好串，当且仅当它可以通过若干次上述操作从 空串 生成。

例如，ab、aabb、aababb 都是好串，而 aab、ba、abbb 不是好串。

现给定一个字符串 s，请判断字符串 s 是否是好串。
输入描述：
在一行中输入一个仅由小写字母a和b组成的字符串 s（1≦∣s∣≦10^5）。
输出描述：
如果字符串 ss 是好串，输出 Good；否则输出 Bad。
*/

//初学stack

#include <bits/stdc++.h>
using namespace std;
int main() {
    stack <int> a;
    string s;
    cin >> s;
    int i, len = s.size();
    for (i = 0; i < len; i++) {
        if (s[i] == 'a')    a.push(1);
        else{
            if (a.empty()) {
                cout << "Bad\n";
                return 0;
            }
            a.pop();
        }
    }
    if (a.empty())cout << "Good\n";
    else    cout << "Bad\n";
    return 0;
}