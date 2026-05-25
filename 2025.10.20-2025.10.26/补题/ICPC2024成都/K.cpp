#include <bits/stdc++.h>
using namespace std;
const int N = 300, S = 1e5,  INF = 0x3f3f3f3f;
struct edge {
    int to, w, c, nxt;
}e[N * 4000 + 5];
int cnt = 1, head[S + 5], dis[S + 5], cur[S + 5], maxf, minc, s = 1, t = 2;
queue<int> q;
bool inq[S + 5], vis[S + 5];
int n, a[N + 5], num, p[35], c[35], top, tot;
map<int, int> book;
void add(int u, int v, int w, int c) {
    e[++cnt].to = v;
    e[cnt].w = w, e[cnt].c = c;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
int gn(int x) {
    if (book.find(x) == book.end()) {
        book[x] = ++num;
        add(num, t, 1, 0);
        add(t, num, 0, 0);
    }
    return book[x];
}
void adde(int x, int step, int num, int v) {
    if (step == top + 1) {
        int y = gn(num);
        add(x, y, 1, v);
        add(y, x, 0, -v);
        return ;
    }
    int tmp = 1;
    for (int i = 0; i <= c[step]; i++) {
        adde(x, step + 1, num * tmp, v + i);
        tmp *= p[step];
    }
    return ;
}
bool spfa() {
    for (int i = 1; i <= num; i++)
        dis[i] = INF, cur[i] = head[i], vis[i] = false;
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
    if (dis[t] == INF) return false;
    return true;
}
int dfs(int x, int flow) {
    if (x == t) {
        maxf += flow;
        return flow;
    }
    vis[x] = true;
    int used = 0, rlow = 0;
    for (int i = cur[x]; i; i = e[i].nxt) {
        cur[x] = i;
        int y = e[i].to, w = e[i].w, c = e[i].c;
        if (!vis[y] && w && dis[y] == dis[x] + c) {
            rlow = dfs(y, min(w, flow - used));
            if (rlow) {
                used += rlow, minc += rlow * c;
                e[i].w -= rlow, e[i ^ 1].w += rlow;
                if (used == flow) break;
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
    cin >> n, num = n + 2;
    for (int i = 1; i <= n; i++) {
        add(s, i + 2, 1, 0);
        add(i + 2, s, 0, 0);
        cin >> a[i];
        top = 0;
        for (int j = 2; j <= sqrt(a[i]); j++)
            if (a[i] % j == 0) {
                p[++top] = j;
                c[top] = 0;
                while (a[i] % j == 0)
                    a[i] /= j, c[top] += 1;
            }
        if (a[i] != 1) p[++top] = a[i], c[top] = 1;
        adde(i + 2, 1, 1, 0);
        int tmp = 0;
        for (int j = 1; j <= top; j++) tmp += c[j];
        tot += tmp;
    }
    dinic();
    cout << tot - minc;
    return 0;
}