#include <bits/stdc++.h>
using namespace std;
const int N = 1000, MOD = 1e9 + 7;
int n, m, dp[N + 5][N + 5][2], cnt[N + 5], ans;
char s[N + 5];
int add(int x, int y) {
    int res = x + y;
    if (res < 0) res += MOD;
    if (res >= MOD) res -= MOD;
    return res;
}
int bct(int x) {
    int res = 0;
    while (x) {
        if (x & 1) res += 1;
        x >>= 1;
    }
    return res;
}
int dfs(int p, int x, int flag) {
    if (x < 0) return 0;
    if (p < x) return dp[p][x][flag] = 0;
    if (dp[p][x][flag] != -1) return dp[p][x][flag];
    dp[p][x][flag] = 0;
    if (flag) {
        if (s[n - p + 1] == '1') {
            dp[p][x][1] = add(dp[p][x][1], dfs(p - 1, x - 1, 1));
            dp[p][x][1] = add(dp[p][x][1], dfs(p - 1, x, 0));
        }
        else dp[p][x][1] = add(dp[p][x][1], dfs(p - 1, x, 1));
    }
    else {
        dp[p][x][0] = add(dp[p][x][0], dfs(p - 1, x - 1, 0));
        dp[p][x][0] = add(dp[p][x][0], dfs(p - 1, x, 0));
    }
    return dp[p][x][flag];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> (s + 1) >> m, n = strlen(s + 1);
    cnt[1] = 0;
    for (int i = 2; i <= n; i++)
        cnt[i] = cnt[bct(i)] + 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) 
            dp[i][j][0] = dp[i][j][1] = -1;
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++)
        if (cnt[i] == m - 1) ans = add(ans, dfs(n, i, 1));
    if (m == 0) ans = 1;
    if (m == 1) ans = add(ans, -1);
    cout << ans;
    return 0;
}