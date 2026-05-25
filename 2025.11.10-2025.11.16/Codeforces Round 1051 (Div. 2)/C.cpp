#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct edge {
    int to, nxt, x, y;
}e[(N << 1) + 5];
int cnt, head[N + 5];
int t, n, now, ans[N + 5];
void add(int u, int v, int x, int y) {
    e[++cnt].to = v;
    e[cnt].x = x, e[cnt].y = y;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}
void dfs(int x, int f) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        if (e[i].x >= e[i].y) dfs(y, x);
    }
    ans[x] = now++;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        if (e[i].x < e[i].y) dfs(y, x);
    }
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        add(u, v, x, y);
        add(v, u, y, x);
    }
    now = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    cnt = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}