#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 2e5;
int t, n, m;
int cnt, head[N + 5];
struct edge {
    int to, nxt;
}e[(M << 1) + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
int dfn[N + 5], low[N + 5], timer;
int stk_u[M + 5], stk_v[M + 5], top;
int deg[N + 5], ans[N + 5];
int bcc[(M << 1) + 5]; 
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++timer;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa) continue;
        if (!dfn[v]) {
            top++;
            stk_u[top] = u;
            stk_v[top] = v;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            
            if (low[v] >= dfn[u]) {
                int bcc_cnt = 0;
                while (true) {
                    int x = stk_u[top], y = stk_v[top];
                    top--;
                    deg[x]++;
                    deg[y]++;
                    bcc[++bcc_cnt] = x;
                    bcc[++bcc_cnt] = y;
                    if (x == u && y == v) break;
                }
                for (int j = 1; j <= bcc_cnt; j++) {
                    int x = bcc[j];
                    if (deg[x] > 0) {
                        ans[x] += deg[x] / 2;
                        deg[x] = 0;
                    }
                }
            }
        } else if (dfn[v] < dfn[u]) {
            top++;
            stk_u[top] = u;
            stk_v[top] = v;
            low[u] = min(low[u], dfn[v]);
        }
    }
    return ;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}