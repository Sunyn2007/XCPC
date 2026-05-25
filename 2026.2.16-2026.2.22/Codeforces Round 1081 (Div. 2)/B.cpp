#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> n >> s, s = ' ' + s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') cnt0 += 1;
        else cnt1 += 1;
    }
    if (cnt0 % 2 == 1) {
        cout << cnt0 << '\n';
        for (int i = 1; i <= n; i++)
            if (s[i] == '0') cout << i << ' ';
        cout << '\n';
    }
    else if (cnt1 % 2 == 0) {
        cout << cnt1 << '\n';
        for (int i = 1; i <= n; i++)
            if (s[i] == '1') cout << i << ' ';
        if (cnt1) cout << '\n';
    }
    else cout << -1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}