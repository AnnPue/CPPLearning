#include <iostream>
#include <string>       // std::string
#include <map>          // std::map
#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include <cctype>       // std::isalpha, std::tolower

using namespace std;

// 排序比较函数：先按次数降序，再按字母升序
bool compare(const pair<char, int>& a, const pair<char, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second; // 次数降序
    } else {
        return a.first < b.first; // 字母升序
    }
}

int main() {
    string s;
    while (getline(cin, s)) { // 读取整行输入
        if (s == "END") {
            break; // 输入END时结束程序
        }

        // map是序自动排序的，这里用来统计字母出现次数
        map<char, int> count; // 用于统计字母出现次数

        // 遍历字符串并统计
        for (char c : s) {
            if (isalpha(c)) { // 只处理字母字符
                char lower_c = tolower(c); // 转为小写统一处理
                count[lower_c]++;
            }
        }

        // 将map转换为vector以便排序
        vector<pair<char, int>> vec(count.begin(), count.end());
        sort(vec.begin(), vec.end(), compare); // 使用自定义比较函数排序

        // 输出结果
        for (auto& pair : vec) {
            cout << pair.first << ":" << pair.second << endl;
        }
    }
    return 0;
}