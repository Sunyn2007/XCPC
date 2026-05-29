#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, a[N + 5];
long long sum[N + 5], ans;
bitset<(2 * N) + 5> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    dp[0] = dp[1] = 1;
    for (int i = 1; i <= n; i++)
        dp |= (dp >> i << i + a[i]);
    for (int i = 1; i <= 2 * n; i++)
        if (dp[i]) ans = max(ans, sum[min(n, i)] - i + 1);
    cout << ans << '\n';
    return 0;
}
/*
dp[i][j] |= dp[i - 1][j];
dp[i][j] |= dp[i - 1][j - a[i]]; (j - a[i] >= i)
*/