/*
∙三长一短选最短；
∙三短一长选最长；
∙参差不齐就选 C。

【名词解释】
【三长一短】三长一短 是指在四个选项长度中恰有一个选项的长度严格小于另外三个选项，且不存在四个选项长度中恰有一个选项的长度严格大于另外三个选项；
【三短一长】三短一长 是指在四个选项长度中恰有一个选项的长度严格大于另外三个选项，且不存在四个选项长度中恰有一个选项的长度严格小于另外三个选项；
【参差不齐】参差不齐 是指既不满足“三长一短”也不满足“三短一长”的情况。
输入描述：
第一行输入一个整数 T (1≦T≦500)，表示题目数。
接下来共有 T 道题，每道题由 4 行字符串组成，分别对应选项 A、B、C、D；每个字符串长度不超过 600，由可见字符（字母、数字、符号等）组成。
输出描述：
对于每道题，输出按照上述坊间传说应选的选项字母（A、B、C 或 D），每个字母独占一行
*/
#include <iostream> //有待完善
using namespace std;
int main() {
    // 关闭同步加速输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;  // 输入题目数
    while (T--) {
        string options[4];
        for (int i = 0; i < 4; ++i) {
            cin >> options[i];  // 输入选项 A、B、C、D
        }

        int lengths[4];
        for (int i = 0; i < 4; ++i) {
            lengths[i] = options[i].length();  // 获取每个选项的长度
        }

        int minLength = lengths[0], maxLength = lengths[0];
        for (int i = 1; i < 4; ++i) {
            if (lengths[i] < minLength) minLength = lengths[i];
            if (lengths[i] > maxLength) maxLength = lengths[i];
        }

        int countMin = 0, countMax = 0;
        for (int i = 0; i < 4; ++i) {
            if (lengths[i] == minLength) countMin++;
            if (lengths[i] == maxLength) countMax++;
        }

        if (countMin == 1 && countMax > 1) {
            // 三长一短，选最短
            for (int i = 0; i < 4; ++i) {
                if (lengths[i] == minLength) {
                    cout << char('A' + i) << '\n';
                    break;
                }
            }
        } else if (countMax == 1 && countMin > 1) {
            // 三短一长，选最长
            for (int i = 0; i < 4; ++i) {
                if (lengths[i] == maxLength) {
                    cout << char('A' + i) << '\n';
                    break;
                }
            }
        } else {
            // 参差不齐，选 C
            cout << 'C' << '\n';
        }
    }
    return 0;
}