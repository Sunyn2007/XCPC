#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
int t, n, cnt, head[N + 5], dp1[N + 5], dp2[N + 5], ans;
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs1(int x, int f) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        dfs1(y, x);
        if (dp1[y] || dp2[y]) dp2[x] += dp1[y] + dp2[y];
        else dp1[x] += 1;
    }
    //cout << x << ' ' << dp1[x] << ' ' << dp2[x] << '\n';
    return ;
}
void dfs2(int x, int f) {
    //cout << x << ' ' << dp1[x] << ' ' << dp2[x] << '\n';
    ans = min(ans, dp2[x]);
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        if (dp1[y] || dp2[y]) dp2[x] -= dp1[y] + dp2[y];
        else dp1[x] -= 1;
        if (dp1[x] || dp2[x]) dp2[y] += dp1[x] + dp2[x]; 
        else dp1[y] += 1;
        dfs2(y, x);
        if (dp1[x] || dp2[x]) dp2[y] -= dp1[x] + dp2[x];
        else dp1[y] -= 1;
        if (dp1[y] || dp2[y]) dp2[x] += dp1[y] + dp2[y];
        else dp1[x] += 1;
    }
    return ;
}
void clean() {
    cnt = 0;
    for (int i = 1; i <= n; i++) 
        head[i] = dp1[i] = dp2[i] = 0;
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    ans = n;
    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans << '\n';
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