#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k;
long long a[N + 5], b[N + 5], s[N + 5], pre[N + 5];
long long syn(long long x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], s[i] = s[i - 1] + a[i];
        pre[i] = min(pre[i - 1], s[i - 1]);
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    if (k % 2 == 0) {
        long long ans = -1e18;
        for (int i = 1; i <= n; i++)
            ans = max(ans, s[i] - pre[i]);
        cout << ans << '\n';
    }
    else {
        long long ans = -1e18, maxn = -1e18;
        for (int i = n; i >= 1; i--) {
            maxn = max(maxn, s[i]);
            ans = max(ans, maxn + syn(b[i]) - pre[i]);
        }
        cout << ans << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}