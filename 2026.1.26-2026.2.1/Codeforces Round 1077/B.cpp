#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> n >> s, s = ' ' + s;
    bool flag = false;
    int len = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') len += 1;
        else {
            ans += 1;
            if (!flag) len -= 1, flag = true;
            else len -= 2;
            if (len > 0) {
                if (len % 3 == 0) ans += len / 3;
                else ans += len / 3 + 1;
            }
            len = 0;
        }
    }
    if (flag) len -= 1;
    if (len > 0) {
        if (len % 3 == 0) ans += len / 3;
        else ans += len / 3 + 1;
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