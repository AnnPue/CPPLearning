#include <iostream>

using namespace std;
int a[34][34];
int main() {
    int n,sum=1;//n范围: [1,34]
    cin>>n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<sum;j++) {
            if (j==0) {
                a[i][j]=1;
                cout<<a[i][j]<<' ';
                continue;
            }
            
            if (j>0&&j<sum) {
                a[i][j]=a[i-1][j]+a[i-1][j-1];
                cout<<a[i][j]<<' ';
            }
        }
        sum++;
        cout<<endl;
    }
    return 0;
}