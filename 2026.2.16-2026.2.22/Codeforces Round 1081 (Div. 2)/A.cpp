#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> n >> s, s = ' ' + s;
    bool flag = false;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i - 1]) flag = true;
        if (s[i] != s[i - 1]) ans += 1;
    }
    if (flag && s[1] != s[n]) cout << ans + 1 << '\n';
    else cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}