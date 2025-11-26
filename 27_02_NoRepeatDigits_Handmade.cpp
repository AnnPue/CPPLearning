#include <iostream>
#include <set>
using namespace std;

int main() {
    set <int> s;
    int t, n, a;
    cin >> t;
    while(t--){
        cin >> n;
        while (n--){
            cin >> a;
            if (!s.count(a)) {
                cout << a << ' ';
                s.insert(a);
            }
        }
        cout << endl;
        s.clear();
    }
    return 0;
}