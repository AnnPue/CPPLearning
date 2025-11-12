#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n, i, j;
    cin >> m >> n;//m: 行数  n: 列数
    vector <int> matrix (n * m + 1);
    for (i = 0; i < n * m; i++){
        cin >> matrix[i];         //先行后列 (从上到下, 从左到右)获得矩阵元素
    }
    
    for (i = 0; i < n; i++){ //为了找全每列, 故重复n次
        for (j = 0; j < n * m; j++){//遍历数组
            if (j % n == i){  //寻找第i列元素
                cout << matrix[j] << ' '; //按行输出
            }
        }
        cout << endl; //一行输出结束后换行
    }
    return 0;
}