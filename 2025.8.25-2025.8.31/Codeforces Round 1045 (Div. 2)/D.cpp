#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct edge {
    int nxt, to;
}e[(N << 1) + 5];
int t, n, head[N + 5], cnt, deg[N + 5], dep[N + 5], f[N + 5][2], g[N + 5], fat[N + 5];
bool flag = false;
void add(int u, int v) {
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    head[u] = cnt;
    return ;
}
void dfs(int x, int fa) {
    fat[x] = fa;
    dep[x] = dep[fa] + 1, g[x] = 1;
    f[x][0] = dep[x];
    for (int i = head[x]; i; i = e[i].nxt) {
        deg[x] += 1;
        int y = e[i].to;
        if (y == fa) continue;
        dfs(y, x);
        g[x] = max(g[x], g[y] + 1);
        if (g[x] >= f[x][0]) f[x][1] = f[x][0], f[x][0] = g[x];
        else if (g[x] > f[x][1]) f[x][1] = g[x];
    }
    if (deg[x] >= 3) flag = true;
    return ;
}
void clean() {
    flag = false, cnt = 0;
    for (int i = 1; i <= n; i++)
        head[i] = 0, deg[i] = 0, f[i][0] = f[i][1] = 0;
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    if (flag) {
        int x = 0, a, c;
        for (int i = 1; i <= n; i++)
            if (deg[i] >= 3 && f[i][0] + f[i][1] > f[x][0] + f[x][1])
                x = i;
        cout << x << ' ' << f[x][0] << ' ' << f[x][1] << '\n';
        bool ok = false;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to, w;
            if (y == fat[x]) w = dep[x];
            else w = g[y] + 1;
            if (w == f[x][0]) a = y;
            if (w < f[x][1]) c = y, ok = true;
        }
        if (!ok) {
            for (int i = head[x]; i; i = e[i].nxt) {
                int y = e[i].to, w;
                if (y == fat[x]) w = dep[x];
                else w = g[y] + 1;
                if (w <= f[x][1]) c = y;
            }
        }
        cout << a << ' ' << x << ' ' << c << '\n';
    }
    else cout << -1 << '\n';
    clean();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}