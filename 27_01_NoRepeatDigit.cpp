#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    for (; !isdigit(c); c = getchar())if (c == '-')f = -1;//处理负数
    for (; isdigit(c); c = getchar())x = x * 10 + c - 48;//字符转数字
    return x * f;
}

int T, n, x;
unordered_map<int, bool>s; //记录是否出现过
void work() {
    s.clear();//清空
    n = read();
    For(i, 1, n) {
        x = read();
        if (!s[x]) { //没有的话，直接输出+标记掉。
            printf("%d ", x);
            s[x] = 1;
        }
    }
    puts("");//换行
}
int main() {
    T = read();
    while (T--)work();
    return 0;
}
/*
原作：牛客 郭旺乐
用于学习，此代码速度非常快
用途：对于每组输入的n个整数，去除重复的整数，保持原有顺序输出。
输入描述：
第一行输入一个整数T，表示测试数据的组数。
对于每组测试数据：
第一行输入一个整数n，表示接下来有n个整数。
第二行输入n个整数。
输出描述：
对于每组测试数据，输出n个整数中不重复的整数，保持原有顺序输出。
*/