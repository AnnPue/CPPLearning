#include <stack>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm> // 用于 remove_if
#include <stdexcept>  // 用于异常处理
using namespace std;

class Solution {
public:
    int solve(string s) {
        // 预处理：移除所有空格
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        if (s.empty()) {
            throw invalid_argument("表达式不能为空");
        }

        stack<int> numbers;
        stack<char> operators;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // 处理数字（包括负数）
            if (isdigit(c) || (c == '-' && (i == 0 || s[i-1] == '(' || isoperator(s[i-1])))) {// 负号作为负数处理(需判断位置)
                int sign = 1;
                int num = 0;
                if (c == '-') {  // 负号处理
                    sign = -1;
                    i++;
                    if (i >= s.length() || !isdigit(s[i])) {  // 检查负号后是否有数字
                        throw invalid_argument("无效的负号位置");
                    }
                }
                // 拼接多位数
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numbers.push(num * sign);  // 存入带符号的数字
                i--;  // 回退一位，避免外层循环跳过字符
            }
            // 左括号直接入栈
            else if (c == '(') {
                operators.push(c);
            }
            // 右括号：计算括号内表达式
            else if (c == ')') {
                if (operators.empty()) {
                    throw invalid_argument("括号不匹配（缺少左括号）");
                }
                while (operators.top() != '(') {
                    computeTop(numbers, operators);
                }
                operators.pop();  // 弹出左括号
            }
            // 处理运算符
            else if (isoperator(c)) {
                // 运算符栈非空且栈顶优先级不低于当前运算符时，先计算
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    computeTop(numbers, operators);
                }
                operators.push(c);
            }
            // 非法字符处理
            else {
                throw invalid_argument("包含非法字符: " + string(1, c));
            }
        }

        // 处理剩余运算符
        while (!operators.empty()) {
            if (operators.top() == '(') {  // 检查未闭合的左括号
                throw invalid_argument("括号不匹配（缺少右括号）");
            }
            computeTop(numbers, operators);
        }

        if (numbers.size() != 1) {  // 确保结果唯一
            throw runtime_error("计算错误，结果不唯一");
        }

        return numbers.top();
    }

private:
    // 判断是否为运算符
    bool isoperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    // 运算符优先级：乘除 > 加减 > 括号
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;  // 左括号优先级最低
    }

    // 执行栈顶运算
    void computeTop(stack<int>& numbers, stack<char>& operators) {
        if (numbers.size() < 2) {
            throw runtime_error("操作数不足，表达式无效");
        }
        int num2 = numbers.top(); numbers.pop();
        int num1 = numbers.top(); numbers.pop();
        char op = operators.top(); operators.pop();

        int result;
        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': 
                if (num2 == 0) {
                    throw runtime_error("除数不能为0");
                }
                // 处理整数除法（向零取整，与C++默认行为一致）
                result = num1 / num2; 
                break;
            default: throw invalid_argument("未知运算符: " + string(1, op));
        }
        numbers.push(result);
    }
};

int main() {
    cout << "请输入表达式（支持 +、-、*、/、()、负数和空格）：" << endl;
    string s;
    getline(cin, s);  // 支持含空格的输入

    try {
        Solution solver;
        cout << "计算结果：" << solver.solve(s) << endl;
    } catch (const exception& e) {
        cerr << "错误：" << e.what() << endl;
        return 1;  // 异常退出
    }

    return 0;
}

/*
 * 16_02_EvaluationAI.cpp
 *
 * Created on: 2025.11.15 Sat.
 * 
 * Enhanced expression evaluator supporting '+', '-', '*', '/', '()', negative numbers, and spaces.
 * Almost made by AI. I have to figure out how it works.
 * 
 * Thanks to copilot and doubao.
 */