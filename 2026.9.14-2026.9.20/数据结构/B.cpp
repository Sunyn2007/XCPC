#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        stack<char> s;
        for (char c : str) {
            if (c == '#') {
                if (!s.empty()) s.pop();
            } else {
                s.push(c);
            }
        }
        if (s.empty()) {
            cout << "NULL" << '\n';
            continue;
        }
        string res;
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        cout << res << '\n';
    }
    return 0;
}
