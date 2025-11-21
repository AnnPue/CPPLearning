#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 关闭同步加速输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, c;
    cin >> n >> c;  // 输入数组长度 n 和目标差值 c
    vector<int> vec(n);
    unordered_map<int, int> freq;  // 存储元素出现频率
    
    // 读入数组并统计频率
    for (int& x : vec) {
        cin >> x;
        freq[x]++;
    }
    
    long long result = 0;
    // 遍历每个元素，统计满足 x - y = c 的数对数量
    for (int num : vec) {
        int target = num - c;  // 需要的配对元素 y = x - c
        result += freq[target];  // 累加 target 的出现次数（不存在则为 0）
    }
    
    cout << result << '\n';
    return 0;
}
