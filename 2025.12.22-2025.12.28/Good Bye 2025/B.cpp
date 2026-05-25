#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> s, n = s.size(), s = ' ' + s;
    int len = 0, ans = 0;
    if (s[1] != 's') s[1] = 's', ans += 1;
    if (s[n] != 's') s[n] = 's', ans += 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'u') {
            if (s[i] == s[i - 1]) len += 1;
            else len = 1;
        }
        else if (len) ans += len / 2, len = 0;
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}