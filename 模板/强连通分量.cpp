#include <bits/stdc++.h>
using namespace std;
const int N = 100000, M = 500000;
struct edge {
    int to, nxt;
} e[M + 5];
int cnt = 0, head[N + 5];
int dfn[N + 5], low[N + 5], tot;
int stk[N + 5], top, bel[N + 5], siz[N + 5], col;
bool ins[N + 5];
int n, m;

void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}

void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, ins[x] = true;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        col++;
        while (true) {
            int y = stk[top--];
            ins[y] = false;
            bel[y] = col, siz[col]++;
            if (y == x) break;
        }
    }
    return ;
}

// 缩点建新图 (DAG) 时如果需要另一套前向星，可另开 head2, e2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    return 0;
}