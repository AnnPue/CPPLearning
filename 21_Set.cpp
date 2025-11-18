#include <set>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set <int> s1 = {5, 2, 8};
    for (auto it = s1.begin(); it != s1.end(); it++){//遍历集合方法一
        cout << *it << endl;
    }
    cout << "-------------" << endl;
    for (auto is : s1){//遍历集合方法二
        cout << is << endl;
    }

    int n;
    cin >> n;
    set<int> s;
    int opt, x;
    while (n--) {
        cin >> opt;
        if (opt != 4) cin >> x;
  
        if (opt == 1) {                 // 插入
            s.insert(x);
        } else if (opt == 2) {          // 删除
            s.erase(x);
        } else if (opt == 3) {          // 查询存在
            cout << (s.count(x) ? "YES\n" : "NO\n");
        } else if (opt == 4) {          // 大小
            cout << s.size() << '\n';
        } else if (opt == 5) {          // 前驱
            auto it = s.lower_bound(x);
            if (it == s.begin()) cout << "-1\n";
            else cout << *prev(it) << '\n';
        } else if (opt == 6) {          // 后继
            auto it = s.upper_bound(x);
            if (it == s.end()) cout << "-1\n";
            else cout << *it << '\n';
        }
    }
    return 0;
}