/*
本程序输入算式, 可输出对应结果, 注意 1.这是整数除法  2.算式中不要有空格*/
#include <stack>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

class Solution {
  public:
    int solve(string s) {
        stack<int> numbers;   // 用来存储操作数
        stack<char> operators; // 用来存储运算符

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // // 跳过空格
            // if (c == ' ') {
            //     continue;
            // }

            // 如果是数字
            if (isdigit(c)) {
                int num = 0;
                // 处理多位数
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numbers.push(num); // 将数字存入数字栈
                i--; // 退回一位，因为外层循环还会自增
            }
            // 如果是左括号，直接放入运算符栈
            else if (c == '(') {
                operators.push(c);
            }
            // 如果是右括号，计算括号内的所有内容
            else if (c == ')') {
                while (operators.top() != '(') {
                    computeTop(numbers, operators);
                }
                operators.pop(); // 弹出左括号
            }
            // 如果是运算符
            else if (c == '+' || c == '-' || c == '*' || c == '/') {
                // 当运算符栈非空，且栈顶运算符优先级不低于当前运算符时，执行运算
                while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                    computeTop(numbers, operators);
                }
                operators.push(c); // 将当前运算符放入运算符栈
            }
        }

        // 处理剩下的运算符
        while (!operators.empty()) {
            computeTop(numbers, operators);
        }

        // 最后数字栈中应只有一个数字，就是结果
        return numbers.top();
    }

  private:
    // 定义运算符的优先级
    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        }
        if (op == '*' || op == '/') {
            return 2;
        }
        return 0;
    }

    // 从栈中取出两个操作数和一个运算符进行计算
    void computeTop(stack<int>& numbers, stack<char>& operators) {
        int num2 = numbers.top();
        numbers.pop();
        int num1 = numbers.top();
        numbers.pop();
        char op = operators.top();
        operators.pop();

        int result = 0;
        if (op == '+') {
            result = num1 + num2;
        } else if (op == '-') {
            result = num1 - num2;
        } else if (op == '*') {
            result = num1 * num2;
        } else if (op == '/') {
            result = num1 / num2;
        }

        numbers.push(result);
    }
};

int main(){
    std::cout << "Please enter an expression with '+', '-', '*', '()' but NO space or '/'\n";
    string s;
    std::cin >> s;
    Solution s1;
    std::cout << s1.solve(s) << endl;
    return 0;
}