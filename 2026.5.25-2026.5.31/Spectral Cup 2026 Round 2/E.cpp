#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, MOD = 998244353;
int t, n, ans, dp[N + 5], sum[N + 5], mx[N + 5], pre[N + 5], suf[N + 5];
int cnt, head[N + 5], deg[N + 5];
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs1(int x, int f) {
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        dfs1(y, x);
        mx[x] = max({mx[x], y, mx[y]});
    }
    return ;
}
void dfs2(int x, int f, int v) {
    if (x > v) ans = (ans + dp[x]) % MOD;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        dfs2(y, x, v);
    }
    return ;
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
        deg[u] += 1, deg[v] += 1;
    }
    int s;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1) s = i;
    if (s == n) ans = 1;
    else {
        dfs1(n, 0);
        dp[s] = 1, sum[s] = 1;
        for (int i = s + 1; i < n; i++) {
            if (mx[i] < i) dp[i] = (sum[i - 1] - sum[mx[i]] + MOD) % MOD;
            sum[i] = (sum[i - 1] + dp[i]) % MOD;
        }
        vector<int> a;
        for (int i = head[n]; i; i = e[i].nxt) a.push_back(e[i].to);
        for (int i = 1; i < a.size(); i++)
            pre[i] = max(pre[i - 1], max(mx[a[i - 1]], a[i - 1]));
        for (int i = a.size() - 2; i >= 0; i--)
            suf[i] = max(suf[i + 1], max(mx[a[i + 1]], a[i + 1]));
        for (int i = 0; i < a.size(); i++)
            dfs2(a[i], n, max(pre[i], suf[i]));
    }
    cout << ans << '\n';
    ans = cnt = 0;
    for (int i = 1; i <= n; i++) 
        dp[i] = sum[i] = mx[i] = pre[i] = suf[i] = head[i] = deg[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}