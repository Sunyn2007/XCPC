#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
int t, n, cnt, head[N + 5], son[N + 5];
char s[N + 5];
double dp[N + 5], ans;
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs1(int x, int f) {
    son[x] = 0;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        dfs1(y, x);
        son[x] += 1;
        dp[x] += dp[y];
    }
    if (s[x] == '0')
    return ;
}
void solve() {
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++) {
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
/*
dp[x] = 
*/