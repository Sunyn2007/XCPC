#include <bits/stdc++.h>
using namespace std;
const int N = 5e3, M = 5e4, INF = 0x3f3f3f3f;
struct edge{
    int to, w, c, nxt;
}e[(M << 1) + 5];
int cnt = 1, head[N + 5], cur[N + 5], dis[N + 5];
queue<int> q;
bool inq[N + 5], vis[N + 5];
int n, m, s, t, maxf, minc;
void add(int u, int v, int w, int c) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].c = c;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
bool spfa() {
    for (int i = 1; i <= n; i++) 
        cur[i] = head[i], dis[i] = INF, vis[i] = false;
    dis[s] = 0;
    q.push(s), inq[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop(), inq[x] = false;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to, w = e[i].w, c = e[i].c;
            if (w && dis[x] + c < dis[y]) {
                dis[y] = dis[x] + c;
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
    vis[x] = true;
    int used = 0, rlow = 0;
    for (int i = cur[x]; i; i = e[i].nxt) {
        cur[x] = i;
        int y = e[i].to, w = e[i].w, c = e[i].c;
        if (!vis[y] && w && dis[x] + c == dis[y]) {
            rlow = dfs(y, min(w, f - used));
            if (rlow) {
                used += rlow, minc += rlow * c;
                e[i].w -= rlow, e[i ^ 1].w += rlow;
                if (used == f) break;
            }
        }
    }
    return used;
}
void dinic() {
    while (spfa()) dfs(s, INF);
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        add(u, v, w, c), add(v, u, 0, -c);
    }
    dinic();
    cout << maxf << ' ' << minc;
    return 0;
}