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
        for (char c : str) s.push(c);
        while (!s.empty()) {
            cout << s.top();
            s.pop();
        }
        cout << '\n';
    }
    return 0;
}
