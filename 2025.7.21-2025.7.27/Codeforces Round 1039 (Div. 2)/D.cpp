#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;
int t, n, a[N + 5];
long long dp[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) dp[i] = dp[i - 1] + i;
        else dp[i] = dp[i - 1] + 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += dp[i];
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