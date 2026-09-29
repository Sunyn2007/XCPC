#include <bits/stdc++.h>
using namespace std;
const int N = 3000, MOD = 998244353;
int t, n, dp[N + 5][N + 5], tot;
int cnt, head[N + 5], sz[N + 5];
struct edge {
    int to, nxt;
}e[2 * N + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs1(int x, int fa) {
    sz[x] = 1;
    dp[x][1] = 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        dfs1(y, x);
        sz[x] += sz[y];
        for (int j = sz[x]; j >= 2; j--)
            for (int k = 1; k <= min(sz[y], j - 1); k++)
                dp[x][j] = (dp[x][j] + 1ll * dp[y][k] * dp[x][j - k] % MOD) % MOD;
    }
    for (int i = 1; i <= sz[x]; i++)
        tot = (tot + dp[x][i]) % MOD;
    return ;
}
void dfs2(int x, int fa) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        for (int j = 2; j <= sz[y]; j++)
            for (int k = 1; k <= min(sz[y], j - 1); k++)
                dp[x][j] = (dp[x][j] - 1ll * dp[y][k] * dp[x][j - k] % MOD + MOD) % MOD;
        sz[x] -= sz[y];
        for (int j = 1; j <= min(sz[x], sz[y]); j++)
            tot = (tot - 1ll * dp[x][j] * dp[y][j] % MOD + MOD) % MOD;
        for (int j = sz[y]; j >= 2; j--)
            for (int k = 1; k <= min(sz[x], j - 1); k++)
                dp[y][j] = (dp[y][j] + 1ll * dp[x][k] * dp[y][j - k] % MOD) % MOD;
        sz[y] += sz[x];
        dfs2(y, x);
        sz[y] -= sz[x];
        for (int j = 2; j <= sz[y]; j++)
            for (int k = 1; k <= min(sz[x], j - 1); k++)
                dp[y][j] = (dp[y][j] - 1ll * dp[x][k] * dp[y][j - k] % MOD + MOD) % MOD;
        sz[x] += sz[y];
        for (int j = sz[y]; j >= 2; j--)
            for (int k = 1; k <= min(sz[y], j - 1); k++)
                dp[x][j] = (dp[x][j] + 1ll * dp[y][k] * dp[x][j - k] % MOD) % MOD;
    }
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    cout << tot << '\n';
    tot = cnt = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = 0;
        for (int j = 1; j <= n; j++)
            dp[i][j] = 0;
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