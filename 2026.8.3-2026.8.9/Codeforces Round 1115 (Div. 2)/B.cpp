#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int syn(int x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> n >> s, s = ' ' + s;
    int len = 0, cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        len += 1;
        if (i == n || s[i] != s[i + 1]) {
            if (s[i] == '0') cnt0 += len - 1;
            else cnt1 += len - 1;
            len = 0;
        }
    }
    if (syn(cnt1 - cnt0) <= 1) cout << cnt1 + cnt0 << '\n';
    else {
        bool fl = false;
        if (cnt1 - 2 == cnt0 && (s[1] == '0' || s[n] == '0')) fl = true, cout << cnt1 + cnt0 + 1 << '\n';
        if (cnt1 - 3 == cnt0 && (s[1] == '0' && s[n] == '0')) fl = true, cout << cnt1 + cnt0 + 2 << '\n';
        if (cnt0 - 2 == cnt1 && (s[1] == '1' || s[n] == '1')) fl = true, cout << cnt1 + cnt0 + 1 << '\n';
        if (cnt0 - 3 == cnt1 && (s[1] == '1' && s[n] == '1')) fl = true, cout << cnt1 + cnt0 + 2 << '\n';
        if (!fl) cout << -1 << '\n';
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