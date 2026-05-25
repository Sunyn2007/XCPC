#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, M = 2e5, MAX = 1e9;
int n, m, a[N + 5], ans[M + 5], now, vis[N + 5];
bool ok = true;
map<pair<int, int>, int> book;
struct edge {
    int to, nxt;
}e[(M << 1) + 5];
int cnt, head[N + 5];
void add(int u, int v) {
    e[++cnt].nxt = head[u];
    e[cnt].to = v;
    head[u] = cnt;
    return ;
}
void dfs(int x) {
    now += 1;
    vis[x] = now;
    int w = MAX;
    while (true) {
        if (book.find(make_pair(x, a[now + 1])) == book.end()) break;
        int num = book[make_pair(x, a[now + 1])];
        ans[num] = w--;
        dfs(a[now + 1]);
    }
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!vis[y]) ok = false;
        else if(vis[y] > vis[x]) {
            int num = book[make_pair(x, y)];
            if (!ans[num]) ans[book[make_pair(x, y)]] = w;
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        book[make_pair(u, v)] = i;
        book[make_pair(v, u)] = i;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    if (!ok) cout << "impossible";
    else for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
    return 0;
}