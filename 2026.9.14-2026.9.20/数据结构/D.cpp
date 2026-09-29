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
        bool ok = true;
        for (char c : str) {
            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (s.empty()) {
                    ok = false;
                    break;
                }
                char top = s.top();
                s.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                    ok = false;
                    break;
                }
            }
        }
        if (!s.empty()) ok = false;
        cout << (ok ? "ok" : "error") << '\n';
    }
    return 0;
}
