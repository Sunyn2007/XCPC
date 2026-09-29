#include <bits/stdc++.h>
using namespace std;
const int N = 3000, MOD = 998244353;
int t, n, f[N + 5][13], fac[N + 5], inv[N + 5];
bool bk[N + 5];
int cnt, head[N + 5], deg[N + 5], rt, dep[N + 5];
struct edge {
    int to, nxt;
}e[2 * N + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    f[x][0] = fa;
    for (int i = 1; i <= 12; i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        dfs(y, x);
    }
    return ;
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 12; i >= 0; i--)
        if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    if (x == y) return x;
    for (int i = 12; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return res;
}
void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = 1ll * i * fac[i - 1] % MOD;
        inv[i] = qpow(fac[i], MOD - 2);
    }
}
int ca(int n, int m) {
    return 1ll * fac[n] * inv[n - m] % MOD;
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
        deg[u] += 1, deg[v] += 1;
    }
    vector<int> a;
    for (int i = 1; i <= n; i++)
        if (deg[i] != 1) rt = i;
    dfs(rt, 0);
    int ans = 0;
    
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--) solve();
    return 0;
}