/*
在一次参议院投票中，所有参议员分为两个阵营：红帮（Radiant, R）和黑帮（Dire, D）。投票过程以轮次进行，所有参议员按给定的顺序 s 循环行动。

行动规则如下：

    轮到某位参议员行动时，他可以行使他的权利：永久禁止另一阵营的一名参议员的投票权。
    被禁止权利的参议员将彻底出局。
    当场上只剩下一种阵营的参议员时，该阵营获胜。

所有参议员都采取最优策略，即总是禁止对方阵营中下一个将要行动的参议员，以尽快消除对手。你需要预测哪个阵营会获胜。

输入描述: 一个字符串 s，代表参议员的阵营和初始顺序。

输出描述: 返回 "Red" 或 "Dark"，代表最终获胜的阵营。
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string predictVictory(string s) {
        int n = s.length();
        queue<int> r_queue, d_queue;
 
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                r_queue.push(i);
            } else {
                d_queue.push(i);
            }
        }
 
        while (!r_queue.empty() && !d_queue.empty()) {
            int r_index = r_queue.front();
            r_queue.pop();
            int d_index = d_queue.front();
            d_queue.pop();
 
            if (r_index < d_index) {
                r_queue.push(r_index + n);
            } else {
                d_queue.push(d_index + n);
            }
        }
 
        return r_queue.empty() ? "Dark" : "Red";
        
    }
};

int main(){
    cout << "请输入一个仅包含 D 和 R 的字符串，代表参议员的阵营和初始顺序" << endl;
    string s;
    cin >> s;
    Solution sol;
    cout << sol.predictVictory(s) << endl;
    return 0;
}