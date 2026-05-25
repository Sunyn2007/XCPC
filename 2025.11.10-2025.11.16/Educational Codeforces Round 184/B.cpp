#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;

void solve() {
    cin >> s, n = s.size();
    s = ' ' + s;
    bool ok = false;
    for (int i = 1; i < n; i++) {
        if (s[i] == '*' && s[i + 1] == '<') ok = true;
        if (s[i] == '*' && s[i + 1] == '*') ok = true;
        if (s[i] == '>' && s[i + 1] == '*') ok = true;
        if (s[i] == '>' && s[i + 1] == '<') ok = true;
    }
    if (ok) cout << -1 << '\n';
    else {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '<') cnt1 += 1;
            if (s[i] == '*') cnt2 += 1;
            if (s[i] == '>') cnt3 += 1;
        }
        cout << max(cnt1 + cnt2, cnt3 + cnt2) << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}