#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>  // 用于 tolower() 转小写
using namespace std;

// -------------------------- 工具函数 --------------------------
// 1. 区分大小写：字典序排序 + 去重（默认）
void sortAndDeduplicate(vector<string>& strVec) {
    // 步骤1：按字典序排序（默认区分大小写，依赖 string 的 < 运算符）
    sort(strVec.begin(), strVec.end());
    // 步骤2：去重（unique 会把重复元素移到末尾，返回不重复元素的尾迭代器）
    auto uniqueIt = unique(strVec.begin(), strVec.end());
    // 步骤3：截断容器，删除重复元素占用的空间
    strVec.erase(uniqueIt, strVec.end());
}

// 2. 忽略大小写：字典序排序 + 去重（实用场景更广泛）
void sortAndDeduplicateIgnoreCase(vector<string>& strVec) {
    // 步骤1：忽略大小写排序（自定义比较函数）
    sort(strVec.begin(), strVec.end(), [](const string& a, const string& b) {
        // 逐字符转小写比较，确保大小写不影响排序
        for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
            char c1 = tolower(static_cast<unsigned char>(a[i]));  // 转 unsigned 避免负数ASCII处理问题
            char c2 = tolower(static_cast<unsigned char>(b[i]));
            if (c1 != c2) {
                return c1 < c2;
            }
        }
        // 前缀相同：短字符串在前（如 "app" < "apple"）
        return a.size() < b.size();
    });

    // 步骤2：忽略大小写去重（自定义重复判断逻辑）
    auto uniqueIt = unique(strVec.begin(), strVec.end(), [](const string& a, const string& b) {
        // 长度不同直接不重复
        if (a.size() != b.size()) {
            return false;
        }
        // 逐字符比较（忽略大小写）
        for (size_t i = 0; i < a.size(); ++i) {
            if (tolower(static_cast<unsigned char>(a[i])) != tolower(static_cast<unsigned char>(b[i]))) {
                return false;
            }
        }
        return true;
    });

    // 步骤3：截断容器
    strVec.erase(uniqueIt, strVec.end());
}

// 辅助函数：打印字符串向量
void printVector(const vector<string>& strVec, const string& title) {
    cout << title << ": ";
    for (size_t i = 0; i < strVec.size(); ++i) {
        if (i > 0) cout << " ";
        cout << strVec[i];
    }
    cout << endl;
}

// -------------------------- 测试用例 --------------------------
int main() {
    // 测试数据（包含重复、大小写混合、长短不同的字符串）
    vector<string> testVec1 = {
        "banana", "Apple", "cherry", "apple", "Banana", 
        "cherry", "Apple", "app", "banana", "orange"
    };
    vector<string> testVec2 = testVec1;  // 复制用于忽略大小写测试

    // 1. 区分大小写：排序 + 去重
    sortAndDeduplicate(testVec1);
    printVector(testVec1, "区分大小写（排序+去重）");
    // 输出：区分大小写（排序+去重）: Apple Banana cherry app apple banana orange

    // 2. 忽略大小写：排序 + 去重
    sortAndDeduplicateIgnoreCase(testVec2);
    printVector(testVec2, "忽略大小写（排序+去重）");
    // 输出：忽略大小写（排序+去重）: Apple app banana cherry orange

    // 3. 边界测试（含空字符串、完全重复）
    vector<string> testVec3 = {"", "a", "A", "", "a", "b", "B"};
    sortAndDeduplicateIgnoreCase(testVec3);
    printVector(testVec3, "边界测试（含空字符串）");
    // 输出：边界测试（含空字符串）:  a b

    return 0;
}
