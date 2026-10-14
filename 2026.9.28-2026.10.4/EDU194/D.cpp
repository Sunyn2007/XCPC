#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
bool check0() {
    for (int i = 1; i <= n; i++)
        if (s[i] == '0' && s[i] == s[i - 1])
            return true;
    return false;
}
bool check1() {
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            if ((s[i] == '+' && s[i - 1] == '-') || (s[i] == '-' && s[i - 1] == '+')) return false;
            if (s[i] == '0' && len % 2 == 0) return false;
            len = 1;
        }
        else len += 1;
    }
    return true;
}
bool check2() {
    int typ = 0, len = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            if ((s[i] == '+' && s[i - 1] == '-') || (s[i] == '-' && s[i - 1] == '+')) {
                if (typ == 2 && len == 2) return false;
                typ = 2;
            }
            else typ = 1;
            len = 1;
        }
        else len += 1;
    }
    return true;
}
void solve() {
    cin >> n >> s, s = '0' + s;
    if (check0()) cout << -1 << '\n';
    else if (check1()) cout << 1 << '\n';
    else if (check2()) cout << 2 << '\n';
    else cout << 3 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}