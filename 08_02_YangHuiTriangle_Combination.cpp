#include <iostream>
#include <vector>
using namespace std;

long long fac(int n){//求阶乘函数, 便于求组合数Cji
    
    if (n==0)return 1;
    int m;
    long long res = 1;
    for (m = 1; m<=n; m++){
        res *= m;
    }
    return res;
}

int main() {
    int n, i, j;//n范围: [1,21]
    cin >> n;
    for (j = 0; j < n; j++){
        for (i = 0; i <= j; i++){//调整好重复次数
            cout << fac(j) / (fac(i) * fac(j - i)) << ' '; //计算组合数Cji
        }
        cout << endl;//一行输出结束后换行
    }
    return 0;
}