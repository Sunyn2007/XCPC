#include <bits/stdc++.h>
using namespace std;
int t, n, k;
long long v1, v2, v3;
string a, b;
void solve() {
    cin >> n >> k >> a >> b;
    string c;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) c += '0';
        else c += '1';
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') cnt1 += 1;
        if (b[i] == '1') cnt2 += 1;
        if (c[i] == '1') cnt3 += 1;
    }
    v1 = 1ll * cnt1 * (n - cnt1), v2 = 1ll * cnt2 * (n - cnt2), v3 = 1ll * cnt3 * (n - cnt3);
    long long ans = v1 + v2;
    int t1 = 1, t2 = 0;
    while (t1 + t2 < (1 << k)) {
        ans += t1 * v3 + t2 / 2 * (v1 + v2);
        int tt1 = t2, tt2 = t1 * 2 + t2;
        t1 = tt1, t2 = tt2;
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