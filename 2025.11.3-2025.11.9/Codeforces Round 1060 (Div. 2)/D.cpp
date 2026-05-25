#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
int cnt, head[N + 5], son[N + 5], dep[N + 5];
int t, n, step;
vector<int> op, nd;
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void syn(int x, int fa) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        syn(y, x);
    }
    op.push_back(1), nd.push_back(0), step += 1;
    if ((dep[x] - dep[1]) % 2 == step % 2) op.push_back(1), nd.push_back(0), step += 1;
    op.push_back(2), nd.push_back(x);
    return ;
}
void dfs1(int x, int fa) {
    dep[x] = dep[fa] + 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa) continue;
        dfs1(y, x);
        if (y == n || son[y]) son[x] = y;
    }
    return ;
}
void dfs2(int x, int fa) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == fa || y == son[x]) continue;
        syn(y, x);
    }
    if (son[x]) {
        op.push_back(1), nd.push_back(0), step += 1;
        if ((dep[x] - dep[1]) % 2 == step % 2) op.push_back(1), nd.push_back(0), step += 1;
        op.push_back(2), nd.push_back(x);
        dfs2(son[x], x);
    }
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs1(1, 0); 
    dfs2(1, 0);
    cout << op.size() << '\n';
    for (int i = 0; i < op.size(); i++) {
        cout << op[i];
        if (op[i] == 2) cout << ' ' << nd[i];
        cout << '\n';
    }
    cout << '\n';
    cnt = 0;
    for (int i = 1; i <= n; i++) head[i] = 0, son[i] = 0;
    op.clear(), nd.clear();
    step = 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}