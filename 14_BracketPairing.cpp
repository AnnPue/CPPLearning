/*
给定一个字符串 S，请检查字符串中仅由括号字符 ‘[’、‘]’、‘(’、‘)’ 组成的子序列是否构成合法括号序列。

合法括号序列的定义如下：

∙ ∙空序列是合法括号序列；

∙ ∙如果 A 是合法括号序列，则 `(A)` 和 `[A]` 都是合法括号序列；

∙ ∙如果 A 和 B 都是合法括号序列，则它们的拼接 AB 也是合法括号序列。

字符串 S 可能包含其他字符，但只需考虑括号部分，忽略其他字符。
输入描述：
在一行中输入一个字符串 S，长度 1≦∣S∣≦10^4，由可见字符组成。
输出描述：
如果字符串 SS 中的括号部分能构成合法括号序列，则输出 true；否则输出 false。
*/

//初学stack

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char> ss;
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            ss.push(s[i]);
        } else if (s[i] == ')' || s[i] == ']') {
            if ( ss.size() == 0 ) {
                flag = false;
                break;
            } else if ((s[i] == ')' && ss.top() == '(') || (s[i] == ']' &&
                       ss.top() == '[')) {
                ss.pop();
            } else {
                flag = false;
                break;
            }
        }
    }
    if (ss.empty() && flag) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}