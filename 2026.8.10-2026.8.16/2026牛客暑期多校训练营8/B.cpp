#include <bits/stdc++.h>
using namespace std;
const int N = 5000, M = 5000, MOD = 998244353;
int t, n, m, a[M + 5], dp[2 * N + 5][N + 5];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    sort(a + 1, a + m + 1);
    int cnt = n - m, now = 1;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (now <= m && i == a[now]) {
            cnt += 1, now += 1;
            for (int j = (i + 1) / 2; j <= min(i, cnt); j++)
                dp[i][j] = dp[i - 1][j - 1];
        }
        else {
            for (int j = (i + 1) / 2; j <= min(i, cnt); j++)
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    cout << dp[2 * n][n] << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}