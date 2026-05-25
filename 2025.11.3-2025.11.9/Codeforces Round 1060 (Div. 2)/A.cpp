#include <bits/stdc++.h>
using namespace std;
int t, n, k;
string s;
void solve() {
    cin >> n >> k >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        bool ok = true;
        for (int j = i - 1; j >= max(i - k + 1, 0); j--)
            if (s[j] == '1') ok = false;
        if (ok) ans += 1;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}