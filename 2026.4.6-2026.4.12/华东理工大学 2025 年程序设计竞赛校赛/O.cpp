#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, MOD = 998244353;
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
int t, n, a[N + 5], p, ans;
int fa[N + 5], sz[N + 5];
vector<int> book[N + 5];
int cnt, head[N + 5];
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
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return ;
    if (sz[x] < sz[y]) swap(x, y); 
    fa[y] = x, sz[x] += sz[y];
    return ;
}
void solve() {
    cin >> n, p = qpow(1ll * n * (n - 1) / 2 % MOD, MOD - 2);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++) cin >> a[i], book[a[i]].push_back(i);
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 2 * i; j <= n; j += i)
            for (int k = 0; k < book[j].size(); k++) {
                int x = book[j][k];
                for (int o = head[x]; o; o = e[o].nxt)
                    if (a[e[o].to] % i == 0 && a[e[o].to] != i) merge(x, e[o].to);
            }
        for (int j = 0; j < book[i].size(); j++) {
            int x = book[i][j];
            for (int k = head[x]; k; k = e[k].nxt) {
                int y = e[k].to;
                if (a[y] % i == 0) {
                    if (find(x) == find(y)) continue;
                    cnt = (cnt + 1ll * sz[find(x)] * sz[find(y)] % MOD) % MOD;
                    //cout << x << ' '  << y << ' ' << cnt << '\n';
                    merge(x, y);
                }
            }
        }
        for (int j = i; j <= n; j += i)
            for (int k = 0; k < book[j].size(); k++)
                fa[book[j][k]] = book[j][k], sz[book[j][k]] = 1;
        //cout << i << ' ' << cnt << '\n';
        ans = (ans + 1ll * i * cnt % MOD * p % MOD) % MOD;
    }
    cout << ans << '\n';
    ans = cnt = 0;
    for (int i = 1; i <= n; i++) 
        head[i] = 0, book[i].clear();
    return ;
} 
void init() {
    for (int i = 1; i <= N; i++) 
        fa[i] = i, sz[i] = 1;
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