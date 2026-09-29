#include <bits/stdc++.h>
using namespace std;
const int N = 1e3, M = 1e3, S = N + M + 2, E = N + 3 * M, INF = 0x3f3f3f3f;
int n, m, a[N + 5], v[N + 5], w[M + 5], x[M + 5], y[M + 5], c[N + 5], tot, mxc;
int s, t, cnt = 1, head[S + 5], cur[S + 5], dis[S + 5], maxf, minc;
queue<int> q;
bool inq[S + 5], vis[S + 5];
bool flag = true;
struct edge {
    int to, w, c, nxt;
}e[2 * E + 5];
void add(int u, int v, int w, int c) {
    e[++cnt].to = v;
    e[cnt].w = w, e[cnt].c = c;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
bool spfa() {
    for (int i = 1; i <= n + m + 2; i++) 
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
    cin >> n >> m, s = n + m + 1, t = n + m + 2;
    for (int i = 1; i <= n; i++) cin >> a[i] >> v[i], a[i] -= v[i], c[i] += v[i];
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> w[i];
        if (x[i] == y[i]) a[x[i]] -= w[i], c[x[i]] += w[i];
        else {
            add(x[i], n + i, INF, 0), add(n + i, x[i], 0, 0);
            add(y[i], n + i, INF, 0), add(n + i, y[i], 0, 0);
            add(n + i, t, w[i], 0), add(t, n + i, 0, 0);
            tot += w[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) flag = false;
        else {
            if (i == 1) add(s, i, a[i], 0), add(i, s, 0, 0);
            else add(s, i, a[i], 1), add(i, s, 0, -1);
        }
    }
    dinic();
    if (maxf < tot) flag = false;
    mxc = c[1] + tot - minc;
    cnt = 1, maxf = minc = 0;
    for (int i = 1; i <= n + m + 2; i++) head[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0 || (i > 1 && mxc - 1 - c[i] < 0)) flag = false;
        else {
            if (i == 1) add(s, i, a[i], 0), add(i, s, 0, 0);
            else add(s, i, min(a[i], mxc - 1 - c[i]), 0), add(i, s, 0, 0);
        }
    }
    for (int i = 1; i <= m; i++)
        if (x[i] != y[i]) {
            add(x[i], n + i, INF, 0), add(n + i, x[i], 0, 0);
            add(y[i], n + i, INF, 0), add(n + i, y[i], 0, 0);
            add(n + i, t, w[i], 0), add(t, n + i, 0, 0);
        }
    dinic();
    if (maxf < tot) flag = false;
    if (flag) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}