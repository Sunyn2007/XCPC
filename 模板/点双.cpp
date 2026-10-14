#include <bits/stdc++.h>
using namespace std;
const int N = 500000, M = 2000000;
struct edge {
    int to, nxt;
} e[(M << 1) + 5], e2[(N << 2) + 5]; // e2 用于圆方树，点数最多 2N，无向边开 4N
int cnt = 1, head[N + 5];
int cnt2 = 0, head2[(N << 1) + 5];
int dfn[N + 5], low[N + 5], tot;
int stk[N + 5], top, col, ext; // col 为点双数量，ext 为圆方树当前方点编号
bool cut[N + 5]; // cut[x] 标记 x 是否为割点
vector<int> vdcc[N + 5];
int n, m;

void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}

void add2(int u, int v) {
    e2[++cnt2].to = v;
    e2[cnt2].nxt = head2[u];
    head2[u] = cnt2;
    return ;
}

void tarjan(int x, int rt) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x;
    if (x == rt && !head[x]) { // 特判孤立点
        col++, ext++;
        vdcc[col].push_back(x);
        add2(ext, x), add2(x, ext);
        top--;
        return ;
    }
    int ch = 0;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!dfn[y]) {
            ch++;
            tarjan(y, rt);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) {
                if (x != rt || ch > 1) cut[x] = true;
                col++, ext++; // 方点编号 ext = n + col
                while (true) {
                    int z = stk[top--];
                    vdcc[col].push_back(z);
                    add2(ext, z), add2(z, ext);
                    if (z == y) break; // 弹到 y 为止，x 留在栈中
                }
                vdcc[col].push_back(x);
                add2(ext, x), add2(x, ext);
            }
        } else {
            low[x] = min(low[x], dfn[y]);
        }
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    ext = n; // 圆方树方点从 n + 1 开始编号
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) continue; // 点双直接过滤自环
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i, i);
    return 0;
}