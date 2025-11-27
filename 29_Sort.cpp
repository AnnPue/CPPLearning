#include<iostream>
#include<set>
using namespace std;

int main(){
    multiset <int>tkt;
    int n,m,a;
    cin>>n>>m;
    while(m--){
        cin >> a;
        tkt.insert(a);
    }
    for (auto i:tkt){
            cout << i <<' ';
    }
}