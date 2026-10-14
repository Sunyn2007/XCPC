#include <bits/stdc++.h>
using namespace std;
const int N = 500000, M = 2000000;
struct edge {
    int to, nxt;
} e[(M << 1) + 5];
int cnt = 1, head[N + 5];
int dfn[N + 5], low[N + 5], tot;
int stk[N + 5], top, bel[N + 5], col;
bool bri[(M << 1) + 5]; // bri[i] 标记第 i 条有向边是否为割边(桥)
vector<int> edcc[N + 5]; // 存储每个边双包含的节点
int n, m;

void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}

void tarjan(int x, int in_edge) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x;
    for (int i = head[x]; i; i = e[i].nxt) {
        if (i == (in_edge ^ 1)) continue;
        int y = e[i].to;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) 
                bri[i] = bri[i ^ 1] = true;
        } else {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        col++;
        while (true) {
            int y = stk[top--];
            bel[y] = col;
            edcc[col].push_back(y);
            if (y == x) break;
        }
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, 0);
    return 0;
}