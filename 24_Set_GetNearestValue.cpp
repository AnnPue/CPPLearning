/*
给定一个初始为空的整数集合，每次执行以下两种操作之一：
∙ ∙ 插入操作 `1 x`：若 x 不在集合中，则插入 x；否则输出 `Already Exist` 并忽略操作。
∙ ∙ 提取操作 `2 x`：若集合不为空，删除并输出集合中与 x 绝对差最小的元素；若存在多个候选，
∙ ∙ ∙ ∙则删除并输出其中较小者；若集合为空，则输出 `Empty`。
输入描述：
第一行包含整数 Q (1≦Q≦105)，表示操作次数。
接下来 Q 行，每行包含操作类型 op 和参数 x，格式为 op x，其中 op∈{1,2}，0≦x≦10^9。
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
    //取消cin与cout的绑定，提高cin效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set <int> s;
    int q, x, op;
    cin >> q;
    while (q--) {
        cin >> op >> x;

        //插入操作
        if (op == 1) {
            if (s.count(x)) cout << "Already Exist" << endl;
            else s.insert(x);
            continue;
        }
        //提取操作
        else {
            //集合为空，输出Empty
            if (s.empty()) {
                cout << "Empty" << endl;
                continue;
            }
            //查找大于等于x的最小元素
            auto itBig = s.lower_bound(x);

            //如果itBig指向集合头，说明所有元素都大于等于x
            if (itBig == s.begin()) {
                cout << *itBig << endl;//输出第一个元素
                s.erase(itBig);//删除该元素
                continue;
            }
            //否则，itBig不是集合头，说明存在小于x的元素，记为itSmall
            auto itSmall = itBig;
            -- itSmall;
            //如果itBig指向集合尾，说明所有元素都小于x
            if (itBig == s.end()) {
                cout << *--itBig << endl;//输出最后一个元素
                s.erase(itBig);//删除该元素
                continue;
            }
            //否则，itBig指向的元素大于等于x，itSmall指向的元素小于x
            //比较两者与x的差值，输出差值较小的那个元素
            //若差值相等，则输出较小的那个元素，即itSmall指向的元素
            int ans = (x - *itSmall) <= (*itBig - x) ? *itSmall : *itBig;
            cout << ans << endl;//输出该元素
            s.erase(ans);//删除该元素
            continue;
        }
    }
    return 0;
}
