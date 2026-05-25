#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, INF1 = 0x7fffffff;
const long long INF2 = 0x3f3f3f3f3f3f3f3f;
int t, n, a[N + 3 + 5];
long long dp[N + 5];
int syn(int x) {
    return (x < 0 ? -x : x);
}
int calc(int l, int r) {
    int minn = INF1, maxn = 0;
    for (int i = l; i <= r; i++)
        minn = min(minn, a[i]), maxn = max(maxn, a[i]);
    return maxn - minn;
}
long long dp_calc(int l, int r) {
    if (l >= r) return 0;
    for (int i = l; i <= r; i++) dp[i] = INF2;
    dp[l - 1] = 0;
    for (int i = l; i <= r; i++) {
        if (i - 2 >= l - 1) dp[i] = min(dp[i], dp[i - 2] + calc(i - 1, i));
        if (i - 3 >= l - 1) dp[i] = min(dp[i], dp[i - 3] + calc(i - 2, i));
    }
    return dp[r];
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = a[1], a[n + 2] = a[2];
    long long ans = dp_calc(1, n);
    if (n > 3)ans = min(ans, dp_calc(2, n - 1) + calc(n, n + 1));
    if (n > 4) ans = min(ans, dp_calc(3, n - 1) + calc(n, n + 2));
    if (n > 4) ans = min(ans, dp_calc(2, n - 2) + calc(n - 1, n + 1));
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}