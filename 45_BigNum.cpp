#include <iostream>
#include <string>
#include <vector>
// 用于反转字符串
#include <algorithm>

using namespace std;

// 将大数字符串转换为向量（低位在前存储）
vector<int> bigNumToVector(const string &numStr)
{
    vector<int> digits;
    // 从字符串末尾（数字的低位）开始遍历，逐个存入向量
    for (auto it = numStr.rbegin(); it != numStr.rend(); ++it)
    {
        // 将字符转成对应的数字（如 '9' -> 9）
        digits.push_back(*it - '0');
    }
    return digits;
}

int main()
{
    string bigNumStr;
    cout << "请输入一个超大整数：";
    cin >> bigNumStr;

    // 转换为低位在前的向量
    vector<int> bigNumVec = bigNumToVector(bigNumStr);

    // 输出验证（低位在前）
    cout << "大数按低位在前存储的结果：";
    for (int d : bigNumVec)
    {
        cout << d << " ";
    }
    cout << endl;

    // 还原为原数字（高位在前）
    cout << "还原为原数字：";
    for (auto it = bigNumVec.rbegin(); it != bigNumVec.rend(); ++it)
    {
        cout << *it;
    }
    cout << endl;

    return 0;
}
