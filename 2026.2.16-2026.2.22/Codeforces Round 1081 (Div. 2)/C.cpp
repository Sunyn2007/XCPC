#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n;
long long h, k, a[N + 5], s, suf[N + 5], pre[N + 5];
void solve() {
    cin >> n >> h >> k;
    s = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    for (int i = 1; i <= n; i++) {
        if (i == 1) pre[i] = a[i];
        else pre[i] = min(a[i], pre[i - 1]);
    }
    for (int i = n; i >= 1; i--) {
        if (i == n) suf[i] = a[i];
        else suf[i] = max(a[i], suf[i + 1]);
    }
    if (h % s == 0)
        cout << h / s * n + max(h / s - 1, 0ll) * k << '\n';
    else {
        long long ans = h / s * n + h / s * k;
        h %= s;
        long long tot = 0;
        for (int i = 1; i <= n; i++) {
            if (i == n) ans += n;
            else {
                tot += a[i];
                if (tot - pre[i] + suf[i + 1] >= h || tot >= h) {
                    ans += i;
                    break;
                }
            }
        }
        cout << ans << '\n';
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