#include <bits/stdc++.h>
using namespace std;
const int N = 5e3, M = 5e4, INF = 0x3f3f3f3f;
struct edge{
    int to, w, c, nxt;
}e[(M << 1) + 5];
int a[25][25], cnt = 1, head[N + 5], cur[N + 5], dis[N + 5];
queue<int> q;
bool inq[N + 5], vis[N + 5];
int n, m, s, t, maxf, minc, id;
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
    for (int &i = cur[x]; i; i = e[i].nxt) {
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
    vis[x] = false;
    return used;
}
void dinic() {
    while (spfa()) dfs(s, INF);
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 3 * n; i++)
        for (int j = 1; j <= 3 * 
            n; j++)
            cin >> a[i][j];
    s = 1, t = 2, id = 3;
    for (int i = 1; i <= 3 * n; i++)
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            add(s, id, INF, 0);
            add(id, s, 0, 0);
        }
    dinic();
    cout << maxf << ' ' << minc;
    return 0;
}