/*
双月的光从城堡侧面的落地窗照射进来，洒在大厅，引人偶进入梦乡。
她们的烦恼不复存在，她们的心愿悉数实现。
在这里的她们，忘记了醒来的方法，沉醉于美梦。
人偶的下一次化装舞会，何时才能开始？

干员丰川祥子（Oblivionis）的失踪令你（博士）感到不安，当你（博士）来到梦城堡时，
大门上显示出若干道谜题，作为博士的你能够解决这些问题吗？
本题包含n个谜题，每个谜题包含四个数字abcd，你可以对数字进行自由排列，
并且允许使用四则运算（加减乘除）和括号，请问是否可以计算出数字24？
请注意取负是非法的，并且任何数字除以0被认为是非法的。

输入格式
第一行一个整数n（n <= 1000），表示谜题数量。
接下来n行，每行四个整数abcd（0 <= a,b,c,d <= 9），由空格分隔。
输出格式
n行结果，Yes或者No（区分大小写），表示谜题是否可解。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 定义四则运算：0-加，1-减，2-乘，3-除
double calc(double a, double b, int op) {
    switch (op) {
        case 0: return a + b;
        case 1: return a - b;
        case 2: return a * b;
        case 3: 
            if (fabs(b) < 1e-9) return 1e18; // 除零返回非法值
            return a / b;
        default: return 1e18;
    }
}

// 检查一组排列是否能通过某种运算符组合和括号得到24
bool checkPermutation(vector<double> nums) {
    // 枚举所有运算符组合（3个运算符，每个4种选择）
    for (int op1 = 0; op1 < 4; op1++) {
        for (int op2 = 0; op2 < 4; op2++) {
            for (int op3 = 0; op3 < 4; op3++) {
                // 5种括号优先级情况
                double res;
                // 情况1: ((a op1 b) op2 c) op3 d
                res = calc(calc(calc(nums[0], nums[1], op1), nums[2], op2), nums[3], op3);
                if (fabs(res - 24) < 1e-6) return true;
                // 情况2: (a op1 (b op2 c)) op3 d
                res = calc(calc(nums[0], calc(nums[1], nums[2], op2), op1), nums[3], op3);
                if (fabs(res - 24) < 1e-6) return true;
                // 情况3: a op1 ((b op2 c) op3 d)
                res = calc(nums[0], calc(calc(nums[1], nums[2], op2), nums[3], op3), op1);
                if (fabs(res - 24) < 1e-6) return true;
                // 情况4: a op1 (b op2 (c op3 d))
                res = calc(nums[0], calc(nums[1], calc(nums[2], nums[3], op3), op2), op1);
                if (fabs(res - 24) < 1e-6) return true;
                // 情况5: (a op1 b) op2 (c op3 d)
                res = calc(calc(nums[0], nums[1], op1), calc(nums[2], nums[3], op3), op2);
                if (fabs(res - 24) < 1e-6) return true;
            }
        }
    }
    return false;
}

// 主函数：处理输入，生成所有唯一排列并检查
int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<int> raw(4);
        for (int i = 0; i < 4; i++) {
            cin >> raw[i];
        }
        vector<double> nums(4);
        for (int i = 0; i < 4; i++) {
            nums[i] = raw[i];
        }
        bool found = false;
        // 生成所有唯一排列（使用next_permutation需要先排序）
        sort(nums.begin(), nums.end());
        do {
            if (checkPermutation(nums)) {
                found = true;
                break;
            }
        } while (next_permutation(nums.begin(), nums.end()));
        cout << (found ? "Yes" : "No") << endl;
    }
    return 0;
}
