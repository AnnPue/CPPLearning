#include <bits/stdc++.h>
using namespace std;

vector<int> tickets;

class Solution {
public:
    /**
     * 有 n 个人在一个队列里购买电影票，每个人要购买的票数由数组 tickets 表示，
     tickets[i] 是第 i 个人要买的票数。第 k 个人是你特别关心的人。

    整个过程遵循以下规则：

    每个人轮流从队首购买一张票，这个过程耗时 1 秒。
    买完一张票后，如果这个人还需要购买更多的票，他会移动到队尾，重新排队。
    如果这个人已经买完了他需要的所有票，他会离开队列。 

    你需要计算并返回第 k 个人买完他所有票总共需要的时间。 
     */
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n=tickets.size();
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        int time=0;
        while(!q.empty()){
            int tem=q.front();
            time++;
            q.pop();
            if(tickets[tem-1]>1){
                q.push(tem);
                tickets[tem-1]--;
            }
            else if(tem-1==k){
                return time;
            }
        }
        return time;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "请输入队列中人数：" << endl;
    cin >> n;
    int t;
    cout << "请输入每个人需要购买的票数：" << endl;
    while(n--){
        cin >> t;
        tickets.push_back(t);
    }
    int k;
    cout << "请输入你特别关心的人的位置（从0开始计数）：" << endl;
    cin >> k;
    cout << sol.timeRequiredToBuy(tickets, k) << endl; // 输出: 13
    return 0;
}