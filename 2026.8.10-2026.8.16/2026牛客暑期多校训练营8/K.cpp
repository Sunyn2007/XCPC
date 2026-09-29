#include <bits/stdc++.h>
using namespace std;
const int N = 1e4, M = 1e4, INF1 = 0x3f3f3f3f;
const long long INF2 = 0x3f3f3f3f3f3f3f3f;
struct edge{
    int to, w, nxt;
    long long c;
}e[(M << 1) + 5];
int T, n, c, a, b, k, cnt, head[N + 5], cur[N + 5];
long long dis[N + 5];
queue<int> q;
bool inq[N + 5], vis[N + 5];
int s, t, maxf;
long long minc;
void add(int u, int v, int w, long long c) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].c = c;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
bool spfa() {
    for (int i = 1; i <= n; i++) 
        cur[i] = head[i], dis[i] = -INF2, vis[i] = false;
    dis[s] = 0;
    q.push(s), inq[s] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop(), inq[x] = false;
        for (int i = head[x]; i; i = e[i].nxt) {
            int y = e[i].to, w = e[i].w;
            long long c = e[i].c;
            if (w && dis[x] + c > dis[y]) {
                dis[y] = dis[x] + c;
                if (!inq[y]) q.push(y), inq[y] = true;
            }
        }
    }
    if (dis[t] != -INF2) return true;
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
    while (spfa()) dfs(s, INF1);
    return ;
}
void solve() {
    cin >> c >> a >> b >> k;
    s = a + b + 1, t = a + b + 2;
    n = a + b + 2;
    cnt = 1;
    for (int i = 1; i <= n; i++) head[i] = 0;
    maxf = 0, minc = 0;
    for (int i = 1; i <= a; i++) {
        int fa, v;
        cin >> fa >> v;
        if (fa == 0) add(s, i, min(v, k), 0), add(i, s, 0, 0);
        else add(fa, i, v, 0), add(i, fa, 0, 0);
    }
    for (int i = 1; i <= b; i++) {
        int fa, v;
        cin >> fa >> v;
        if (fa == 0) add(a + i, t, min(v, k), 0), add(t, a + i, 0, 0);
        else add(a + i, a + fa, v, 0), add(a + fa, a + i, 0, 0);
    }
    for (int i = 1; i <= c; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, a + y, 1, w), add(a + y, x, 0, -w);
    }
    dinic();
    if (maxf == k) cout << minc << '\n';
    else cout << -1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) solve();
    return 0;
}