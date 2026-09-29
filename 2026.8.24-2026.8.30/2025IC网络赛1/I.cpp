#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 1e5, INF = 0x3f3f3f3f;
struct edge {
    int to, w, nxt;
}e[(M << 1) + 5];
struct syn {
    int x, y;
    bool operator <(const syn &b) const {
        if (x == b.x) return y > b.y;
        return x > b.x;
    }
}d[N + 5];
int cnt, head[N + 5];
int n, m, v, t;
void add(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
syn add(syn a, int w) {
    if (a.y + w > v) a.x += 1, a.y = w;
    else a.y += w;
    return a;
}
void dij() {
    bool vis[N + 5];
    for (int i = 1; i <= n; i++) d[i].x = d[i].y = INF, vis[i] = false;
    d[t].x = 1, d[t].y = 0;
    priority_queue<pair<syn, int>> q;
    q.push(make_pair(d[t], t));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to, w = e[i].w;
            if (d[y] < add(d[x], w)) {
                d[y] = add(d[x], w);
                q.push(make_pair(d[y], y));
            }
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> v >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    dij();
    for (int i = 1; i <= n; i++) {
        if (d[i].x == INF) cout << -1 << ' ';
        else cout << d[i].x << ' ';
    }
    return 0;
}