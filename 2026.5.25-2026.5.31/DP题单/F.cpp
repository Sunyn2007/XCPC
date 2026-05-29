#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int t, x, y;
long long dp[35][2][2];
bool vis[35][2][2];
bool gb(int x, int k) {
    if ((x >> k - 1) & 1) return true;
    return false;
}
long long dfs(int p, int f1, int f2) {
    if (vis[p][f1][f2]) return dp[p][f1][f2];
    vis[p][f1][f2] = true;
    if (f1 && f2) {
        if (gb(x, p) && gb(y, p)) dp[p][1][1] = (dfs(p - 1, 1, 0) + dfs(p - 1, 0, 1) + dfs(p - 1, 0, 0)) % MOD;
        else if (gb(x, p)) dp[p][1][1] = (dfs(p - 1, 1, 1) + dfs(p - 1, 0, 1)) % MOD;
        else if (gb(y, p)) dp[p][1][1] = (dfs(p - 1, 1, 1) + dfs(p - 1, 1, 0)) % MOD; 
        else dp[p][1][1] = dfs(p - 1, 1, 1);
    }
    else if (f1) {
        if (gb(x, p)) dp[p][1][0] = (dfs(p - 1, 0, 0) + dfs(p - 1, 0, 0) + dfs(p - 1, 1, 0)) % MOD;
        else dp[p][1][0] = (dfs(p - 1, 1, 0) + dfs(p - 1, 1, 0)) % MOD;
    }
    else if (f2) {
        if (gb(y, p)) dp[p][0][1] = (dfs(p - 1, 0, 0) + dfs(p - 1, 0, 0) + dfs(p - 1, 0, 1)) % MOD;
        else dp[p][0][1] = (dfs(p - 1, 0, 1) + dfs(p - 1, 0, 1)) % MOD;
    }
    else dp[p][0][0] = (dfs(p - 1, 0, 0) + dfs(p - 1, 0, 0) + dfs(p - 1, 0, 0)) % MOD;
    return dp[p][f1][f2];
}
void solve() {
    cin >> x >> y;
    memset(dp, 0, sizeof(dp)), memset(vis, 0, sizeof(vis));
    vis[0][0][0] = vis[0][0][1] = vis[0][1][0] = vis[0][1][1] = true;
    dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = 1;
    long long ans = 0;
    for (int i = 30; i >= 1; i--) {
        int f1, f2;
        if (x >= (1 << i - 1)) {
            if (x >= (1 << i)) f1 = 0;
            else f1 = 1;
            if (y >= (1 << i - 1)) f2 = 0;
            else f2 = 1;
            ans = (ans + dfs(i - 1, f1, f2) * i) % MOD;
        }
        if (y >= (1 << i - 1)) {
            if (y >= (1 << i)) f2 = 0;
            else f2 = 1;
            if (x >= (1 << i - 1)) f1 = 0;
            else f1 = 1;
            ans = (ans + dfs(i - 1, f1, f2) * i) % MOD;
        }
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