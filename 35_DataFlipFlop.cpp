#include <iostream>
using namespace std;

// D触发器类：上升沿触发，带清零功能
class DFlipFlop {
private:
    bool Q;          // 主输出
    bool Q_bar;      // 反相输出
    bool prev_clk;   // 上一个时钟状态，用于检测上升沿

public:
    // 构造函数：初始状态清零
    DFlipFlop() : Q(false), Q_bar(true), prev_clk(false) {}

    // 更新触发器状态
    void update(bool D, bool CLK, bool CLR) {
        // 清零优先：CLR低电平有效
        if (!CLR) {
            Q = false;
            Q_bar = true;
            prev_clk = CLK;
            return;
        }

        // 检测时钟上升沿：上一个CLK是0，当前是1
        bool rising_edge = (!prev_clk) && CLK;
        if (rising_edge) {
            Q = D;
            Q_bar = !D;
        }
        // 非上升沿：保持状态

        prev_clk = CLK; // 更新上一个时钟状态
    }

    // 获取输出
    bool getQ() const { return Q; }
    bool getQbar() const { return Q_bar; }
};

// 测试代码
int main() {
    DFlipFlop dff;
    // 测试序列：D, CLK, CLR
    //CLR：清零端，低电平有效时强制Q=0
    //PRE：置位端，低电平有效时强制Q=1
    struct TestCase { bool D; bool CLK; bool CLR; } test_cases[] = {
        {0, 0, 1}, {0, 1, 1}, // 上升沿，D=0 → Q=0
        {1, 1, 1}, {1, 0, 1}, // 无触发沿，保持Q=0
        {1, 1, 1},            // 上升沿，D=1 → Q=1
        {0, 1, 1}, {0, 0, 1}, // 无触发沿，保持Q=1
        {1, 1, 0}             // 清零，强制Q=0
    };

    cout << "D\tCLK\tCLR\tQ\n";
    cout << "-------------------------\n";
    for (auto &tc : test_cases) {
        dff.update(tc.D, tc.CLK, tc.CLR);
        cout << tc.D << "\t" << tc.CLK << "\t" << tc.CLR << "\t" << dff.getQ() << endl;
    }
    return 0;
}
