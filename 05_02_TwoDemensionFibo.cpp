#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long a[1001][1001]; 

int main(){
    int n, m; 
    cin >> n >> m; 

    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= m; j++){ 
            if(i == 1 && j == 1) a[i][j] = 1; 
            else if(i == 1) a[i][j] = a[i][j - 1]; 
            else if(j == 1) a[i][j] = a[i - 1][j]; 
            else a[i][j] = (a[i - 1][j] + a[i][j - 1]) % MOD; 
        }
    }
    
    cout << a[n][m] % MOD;
}