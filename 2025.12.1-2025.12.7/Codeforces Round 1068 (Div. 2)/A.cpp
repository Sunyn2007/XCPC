#include <bits/stdc++.h>
using namespace std;
int t, n, k;
string s;
void solve() {
    cin >> n >> k >> s, s = ' ' + s;
    int now = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') now = k;
        else {
            if (now) now -= 1;
            else ans += 1;
        }
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