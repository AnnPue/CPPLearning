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

    你需要计算并返回第 k 个人买完他所有票时的时间。 
     */
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        for(int i = 0; i < tickets.size(); i++){
            q.push(i);//将队列中的人用编号表示，编号从0开始
        }
        int time = 0, index;
        while(1){
            index = q.front();//获得队首之人编号
            time++;//计时
            q.pop();//队首之人买一张票，离开队首
            if(tickets[index] > 1){//若还需买票
                q.push(index);//回到队尾
                tickets[index]--;//要买票的数量减一
            }
            else if(index == k){//若为特别关心的人且买完票了
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
        tickets.push_back(t);//将每个人需要购买的票数存入tickets数组
    }
    int k;
    cout << "请输入你特别关心的人的位置（从0开始计数）：" << endl;
    cin >> k;
    cout << sol.timeRequiredToBuy(tickets, k) << endl;
    return 0;
}
