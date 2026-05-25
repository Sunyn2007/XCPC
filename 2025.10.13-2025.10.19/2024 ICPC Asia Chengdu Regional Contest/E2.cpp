#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5, Q = 1e5, MOD = 998244353;
struct edge{
    int to, nxt;
}e[(N << 1) + 5];
int t, n, q, cnt, head[N + 5], f[N + 5][21], dep[N + 5], s[N + 5][21], dp1[N + 5], dp2[N + 5];
int qu[Q + 5], qv[Q + 5], ans[Q + 5];
vector<int> qq[N + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
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
void dfs1(int x, int fa) {
    f[x][0] = fa;
    dep[x] = dep[fa] + 1;
    dp1[x] = 1;
    for (int i = 1; i <= 20; i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        dfs1(y, x);
        dp1[x] = 1ll * dp1[x] * (dp1[y] + 1) % MOD;
    }
    dp2[x] = dp1[x];
    return ;
}
void dfs2(int x, int fa) {
    s[x][0] = dp1[x];
    for (int i = 1; i <= 20; i++)
        s[x][i] = (s[x][i - 1] + s[f[x][i - 1]][i - 1]) % MOD;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        dfs2(y, x);
    }
    return ;
}
int lca(int x, int y) {
    if (dep[y] > dep[x]) swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    if (x == y) return x;
    for (int i = 20; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
int slca(int x, int y) {
    int res = 0;
    if (dep[y] > dep[x]) swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[f[x][i]] >= dep[y]) res = (res + s[x][i]) % MOD, x = f[x][i];
    if (x == y) return res;
    for (int i = 20; i >= 0; i--)
        if (f[x][i] != f[y][i]) {
            res = (res + s[x][i]) % MOD;
            res = (res + s[y][i]) % MOD;
            x = f[x][i], y = f[y][i];
        }
    res = (res + s[x][0]) % MOD;
    res = (res + s[y][0]) % MOD;
    return res;
}
void dfs3(int x, int fa) {
    if (n == 98) cout << x << ' ' << dp2[x] << '\n';
    for (int i = 0; i < qq[x].size(); i++)
        ans[qq[x][i]] = (ans[qq[x][i]] + dp2[x]) % MOD;
    qq[x].clear();
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        int tmpx = dp2[x], tmpy = dp2[y];
        dp2[x] = 1ll * dp2[x] * qpow((dp2[y] + 1) % MOD, MOD - 2) % MOD;
        dp2[y] = 1ll * dp2[y] * (dp2[x] + 1) % MOD;
        if (n == 98) cout << tmpx << ' ' << dp2[x] << ' ' << tmpy << ' ' << dp2[y] << '\n';
        dfs3(y, x);
        dp2[y] = 1ll * dp2[y] * qpow((dp2[x] + 1) % MOD, MOD - 2) % MOD;
        dp2[x] = 1ll * dp2[x] * (dp2[y] + 1) % MOD;
    }
    return ;
} 
void solve() {
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        add(i, x), add(x, i);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= q; i++) {
        cin >> qu[i] >> qv[i];
        int l = lca(qu[i], qv[i]);
        qq[l].push_back(i);
        ans[i] = slca(qu[i], qv[i]);
    }
    dfs3(1, 0);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
    cnt = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    return ;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}