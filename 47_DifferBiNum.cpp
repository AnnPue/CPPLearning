#include <iostream>
#include <vector>
using namespace std;

void ToBinary(int n, vector<int> &res) // 十转二，将结果存储在res中
{
    if (n > 1)
    {
        ToBinary(n / 2, res);
    }
    else
    {
        res.push_back(n);
        return;
    }
    res.push_back(n % 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num1, num2;
        cin >> num1 >> num2;
        vector<int> res1, res2;
        ToBinary(num1, res1);
        ToBinary(num2, res2);
        int i = res1.size() - 1, j = res2.size() - 1, cnt = 0;
        while (i >= 0 && j >= 0)
        {
            if (res1[i] != res2[j])
            {
                cnt++;
            }
            i--;
            j--;
        }
        // 若一个数的位数多于另一个，则继续计数
        while (i >= 0)
        {
            if (res1[i] == 1)
            {
                cnt++;
            }
            i--;
        }
        while (j >= 0)
        {
            if (res2[j] == 1)
            {
                cnt++;
            }
            j--;
        }
        cout << cnt << endl;
    }
}