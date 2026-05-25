#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
int cnt, head[N + 5];
int t, n;
long long a[N + 5], dp[N + 5], d1[N + 5], d2[N + 5], val[N + 5], sum[N + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs(int x, int f) {
    val[x] = 0, sum[x] = a[x];
    d1[x] = d2[x] = 0;
    dp[x] = 0;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        dfs(y, x);
        sum[x] += sum[y];
        val[x] += val[y] + sum[y];
        if (d1[y] + 1 >= d1[x]) d2[x] = d1[x], d1[x] = d1[y] + 1;
        else if (d1[y] + 1 > d2[x]) d2[x] = d1[y] + 1;
    }
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        long long d;
        if (d1[y] + 1 == d1[x]) d = d2[x];
        else d = d1[x];
        dp[x] = max({dp[x], val[x] - val[y] + dp[y], val[x] + d * sum[y]});
    }
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << '\n';
    cnt = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}