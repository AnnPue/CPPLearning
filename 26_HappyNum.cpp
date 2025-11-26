/*
 给定一个正整数，请你判断这个数是不是快乐数。
快乐数：对于一个正整数，每次把他替换为他每个位置上的数字的平方和，
        如果这个数能变为 1 则是快乐数，如果不可能变成 1 则不是快乐数。 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool happynum(int n) {
        if (n == 1) return true;
        else if (n < 10) return false;
        int i = 0;
        int sum = 0;
        while (n != 0){
            i = n % 10;
            sum += i * i;
            n /= 10;
        }
        return happynum(sum);
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    if (s.happynum(n)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}