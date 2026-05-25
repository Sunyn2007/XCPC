#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
int cnt, head[N + 5], deg[N + 5], dp1[N + 5], dp2[N + 5], dp3[N + 5];
int t, n, m, ans;
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs(int x, int f) {
    dp1[x] = dp2[x] = dp3[x] = 0;
    if (deg[x] >= 2) dp1[x] = 1;
    if (deg[x] >= 3) dp2[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        dfs(y, x);
        if (deg[x] >= 3) dp1[x] = max(dp1[x], dp2[y] + 1);
        if (deg[x] >= 4) {
            dp3[x] = max(dp3[x], dp2[y] + dp2[x]);
            dp2[x] = max(dp2[x], dp2[y] + 1);
        }
    }
    ans = max({ans, dp1[x], dp2[x], dp3[x]});
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
        deg[u] += 1, deg[v] += 1;
    }
    ans = 0;
    dfs(1, 0);
    cout << ans << '\n';
    cnt = 0;
    for (int i = 1; i <= n; i++)
        head[i] = 0, deg[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}