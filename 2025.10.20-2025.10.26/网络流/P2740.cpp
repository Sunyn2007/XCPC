#include <bits/stdc++.h>
using namespace std;
const int N = 200, M = 200, INF = 0x3f3f3f3f;
struct edge {
    int to, w, nxt;
}e[(N << 1) + 5];
int cnt = 1, head[M + 5], cur[M + 5], dis[M + 5];
bool inq[M + 5];
queue<int> q;
int n, m, s, t, maxf;
void add(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
bool bfs() {
    for (int i = 1; i <= m; i++)
        dis[i] = INF, cur[i] = head[i];
    dis[s] = 0;
    q.push(s), inq[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop(), inq[x] = false;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to, w = e[i].w;
            if (w && dis[x] + 1 < dis[y]) {
                dis[y] = dis[x] + 1;
                if (!inq[y]) q.push(y), inq[y] = true;
            }
        }
    }
    if (dis[t] != INF) return true;
    return false;
}
int dfs(int x, int f) {
    if (x == t) {
        maxf += f;
        return f;
    }
    int rlow = 0, used = 0;
    for (int i = cur[x]; i; i = e[i].nxt) {
        cur[x] = i;
        int y = e[i].to, w = e[i].w;
        if (w && dis[y] == dis[x] + 1) {
            rlow = dfs(y, min(w, f - used));
            if (rlow) {
                used += rlow;
                e[i].w -= rlow;
                e[i ^ 1].w += rlow;
                if (used == f) break;
            }
        }
    }
    return used;
}
void dinic() {
    while (bfs()) dfs(s, INF);
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m, s = 1, t = m;
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, 0);
    }
    dinic();
    cout << maxf;
    return 0;
}