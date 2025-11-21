#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set <int> s;
    int q, x, op;
    cin >> q;
    while (q--) {
        cin >> op >> x;
        switch (op) {
            case 1:
                if (s.count(x)) cout << "Already Exist" << endl;
                else s.insert(x);
                break;
            default:
                if (s.empty()) {
                    cout << "Empty" << endl;
                    break;
                }
                auto itBig = s.lower_bound(x);
                if (itBig == s.begin()) {
                    cout << *itBig << endl;
                    s.erase(itBig);
                    break;
                }
                auto itSmall = s.lower_bound(x);
                -- itSmall;
                if (itBig == s.end()) {
                    cout << *--itBig << endl;
                    s.erase(itBig);
                    break;
                }
                int ans = (x - *itSmall) <= (*itBig - x) ? *itSmall : *itBig;
                cout << ans << endl;
                s.erase(ans);
                break;
        }
    }
    return 0;
}
