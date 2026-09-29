#include <bits/stdc++.h>
using namespace std;
const int N = 12, M = 30, INF = 0x3f3f3f3f;
struct edge {
    int to, nxt, w;
}e[(M << 1) + 5];
int cnt, head[N + 5], cur[N + 5], dis[N + 5];
bool inq[N + 5];
queue<int> q;
int T, sum, f[8], n, s, t, maxf;
void add(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u]= cnt;
    return ;
}
bool bfs() {
    for (int i = 1; i <= n; i++)
        cur[i] = head[i], dis[i] = INF;
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
        if (w && dis[x] + 1 == dis[y]) {
            rlow = dfs(y, min(f - used, w));
            if (rlow) {
                used += rlow, e[i].w -= rlow, e[i ^ 1].w += rlow;
                if (used == f) break;
            }
        }
    }
    return used;
}
int dinic() {
    maxf = 0;
    while (bfs()) dfs(s, INF);
    return maxf;
}
bool check(int x) {
    cnt = 1;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1; i <= 7; i++) 
        add(s, i, f[i]), add(i, s, 0);
    add(1, 8, INF), add(8, 1, 0);
    add(2, 9, INF), add(9, 2, 0);
    add(3, 8, INF), add(8, 3, 0), add(3, 9, INF), add(9, 3, 0);
    add(4, 10, INF), add(10, 4, 0);
    add(5, 8, INF), add(8, 5, 0), add(5, 10, INF), add(10, 5, 0);
    add(6, 9, INF), add(9, 6, 0), add(6, 10, INF), add(10, 6, 0);
    add(7, 8, INF), add(8, 7, 0), add(7, 9, INF), add(9, 7, 0), add(7, 10, INF), add(10, 7, 0);
    add(8, t, x), add(t, 8, 0), add(9, t, x), add(t, 9, 0), add(10, t, x), add(t, 10, 0);
    return (dinic() == 3 * x);
}
void solve() {
    n = 12, s = 11, t = 12;
    cin >> sum, sum;
    for (int i = 1; i <= 7; i++) cin >> f[i];
    int l = 0, r = sum / 3, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) solve();
}