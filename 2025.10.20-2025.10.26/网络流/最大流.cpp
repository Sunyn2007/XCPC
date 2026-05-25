#include <bits/stdc++.h>
using namespace std;
const int N = 200, M = 5000, INF1 = 0x7fffffff, INF2 = 0x3f3f3f3f;
struct edge {
    int to, nxt, w;
}e[(M << 1) + 5];
int cnt = 1, head[N + 5], cur[N + 5], dis[N + 5];
bool inq[N + 5];
queue<int> q;
int n, m, s, t;
long long maxf;
void add(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
bool bfs() {
    for (int i = 1; i <= n; i++) 
        cur[i] = head[i], dis[i] = INF2;
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
    if (dis[t] != INF2) return true;
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
            rlow = dfs(y, min(f - used, w));
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
int dinic() {
    while (bfs()) dfs(s, INF1);
    return maxf;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, 0);
    }
    dinic();
    cout << maxf << '\n';
    return 0;
}