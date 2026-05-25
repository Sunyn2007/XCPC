#include <bits/stdc++.h>
using namespace std;
const int N = 3e5, INF = 0x7fffffff;
int t, n, a[N + 5], dp[N + 5][3];
void solve() {
    dp[0][0] = 0, dp[0][1] = -INF, dp[0][2] = -INF;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > dp[i - 1][0]) dp[i][0] = dp[i - 1][0] + 1;
        else if (a[i] < dp[i - 1][0]) dp[i][0] = dp[i - 1][0] - 1;
        else dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        if (a[i] > dp[i - 1][1]) dp[i][2] = dp[i - 1][1] + 1;
        else if(a[i] < dp[i - 1][1]) dp[i][2] = dp[i - 1][1] - 1;
        else dp[i][2] = dp[i - 1][1];
        if (a[i] > dp[i - 1][2]) dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);
        else if(a[i] < dp[i - 1][2]) dp[i][2] = max(dp[i][2], dp[i - 1][2] - 1);
        else dp[i][2] = max(dp[i][2], dp[i - 1][2]);
    }
    cout << max(dp[n][1], dp[n][2]) << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}