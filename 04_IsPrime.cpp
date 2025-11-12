#include <cmath>
#include <iostream>
using namespace std;
bool is_prime(int num) {
    if (num <= 1) {
        return false; // 1不是素数，小于1的数也不考虑
    }
    if (num == 2) {
        return true; // 2是唯一的偶数素数
    }
    if (num % 2 == 0) {
        return false; // 偶数（除了2）都不是素数
    }

    // 只需检查奇数因子
    for (int i = 3; i <= sqrt(num); i += 2) {//只需要检查小于根号n的数(数论知识)
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(is_prime(a[i])){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}