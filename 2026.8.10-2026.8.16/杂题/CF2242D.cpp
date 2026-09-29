#include <bits/stdc++.h>
using namespace std;
const int N = 5e3, M = 5e3, INF = INT_MAX;
int t, n, m, l1[N + 5][10], l2[N + 5][10], dp[N + 5][M + 5];
string a, b;
void solve() {
    cin >> a >> b, n = a.size(), m = b.size();
    a = ' ' + a, b = ' ' + b;
    l1[0][0] = l2[0][0] = 0;
    for (int i = 1; i <= 9; i++) l1[0][i] = l2[0][i] = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 9; j++) {
            int num = a[i] - '0';
            if (j == num) l1[i][j] = 1;
            else l1[i][j] = (l1[i - 1][(j - num + 10) % 10] == INF ? INF : l1[i - 1][(j - num + 10) % 10] + 1);
        }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= 9; j++) {
            int num = b[i] - '0';
            if (j == num) l2[i][j] = 1;
            else l2[i][j] = (l2[i - 1][(j - num + 10) % 10] == INF ? INF : l2[i - 1][(j - num + 10) % 10] + 1);
        }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        if (l1[i][0] != INF) dp[i][0] = dp[i - l1[i][0]][0];
    for (int i = 1; i <= m; i++)
        if (l2[i][0] != INF) dp[0][i] = dp[0][i - l2[i][0]];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= 9; k++)
                if (l1[i][k] != INF && l2[j][k] != INF && dp[i - l1[i][k]][j - l2[j][k]] != -1)
                    dp[i][j] = max(dp[i][j], dp[i - l1[i][k]][j - l2[j][k]] + 1);
            if (l1[i][0] != INF) dp[i][j] = max(dp[i][j], dp[i - l1[i][0]][j]);
            if (l2[j][0] != INF) dp[i][j] = max(dp[i][j], dp[i][j - l2[j][0]]);
        }
    cout << dp[n][m] << '\n';
    return ;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}