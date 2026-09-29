#include <bits/stdc++.h>
using namespace std;
const int N = 5000, M = 10000;
long long INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
int cnt1, head1[N + 5], cnt2, head2[N + 5];
long long dp[N + 5][N + 5];
struct edge {
    int to, nxt, w;
}e1[2 * N + 5], e2[2 * M + 5];
void add1(int u, int v, int w) {
    e1[++cnt1].to = v;
    e1[cnt1].w = w;
    e1[cnt1].nxt = head1[u];
    head1[u] = cnt1;
    return ;
}
void add2(int u, int v) {
    e2[++cnt2].to = v;
    e2[cnt2].nxt = head2[u];
    head2[u] = cnt2;
    return ;
}
void syn(int k) {
    priority_queue<pair<long long, int> > q;
    bool vis[N + 5];
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
        if (dp[i][k] != INF) q.push(make_pair(-dp[i][k], i));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int i = head1[x]; i; i = e1[i].nxt) {
            int y = e1[i].to, w = e1[i].w;
            if (dp[x][k] + w < dp[y][k]) {
                dp[y][k] = dp[x][k] + w;
                q.push(make_pair(-dp[y][k], y));
            }
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add1(u, v, w), add1(v, u, w);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add2(u, v), add2(v, u);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            for (int j = 1; j <= n; j++) {
                dp[j][i] = min(dp[j][i], dp[j][i - 1]);
                for (int k = head2[j]; k; k = e2[k].nxt)
                    dp[j][i] = min(dp[j][i], dp[e2[k].to][i - 1]);
            }
        }
        syn(i);
    }
    for (int i = 0; i <= n; i++) {
        long long res = 0;
        for (int j = 1; j <= n; j++) res += dp[j][i];
        cout << res << '\n';
    }
    return 0;
}