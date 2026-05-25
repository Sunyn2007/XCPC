#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int t, n, d, cnt, head[N + 5], sz[N + 5];
int dp1[N + 5][N + 5], dp2[N + 5][N + 5], dp3[N + 5][N + 5];
long long ans;
struct edge {
    int to, nxt;
}e[(N << 1) + 5];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
    return ;
}
void dfs(int x, int f) {
    
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (y == f) continue;
        dfs(y, x);
        for (int j = 1; j < d; j++)
            ans += 1ll * dp1[y][j] * dp3[x][d - j] + 1ll * dp3[y][j] * dp1[x][d - j];
        for (int j = 1; j <= d; j++)
            dp3[x][j] += dp2[y][j - 1] + dp3[y][j - 1];
        for (int j = 1; j <= sz[x]; j++)
            for (int k = 1; k <= sz[y]; k++)
                if (j + k <= d) dp2[x][j + k] += dp1[x][j] * dp1[y][k];
        for (int j = 1; j <= d; j++)
            dp1[x][j] += dp1[y][j - 1];
        sz[x] += sz[y];
    }
    sz[x] += 1;
    dp1[x][1] += 1;
    ans += dp1[x][d];
    ans += dp2[x][d];
    ans += dp3[x][d];
    return ;
}
void solve() {
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    } 
    dfs(1, 0);
    cout << ans << '\n';
    cnt = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = sz[i] = 0;
        for (int j = 0; j <= d; j++)
            cout << i << ' ' << j << ' ' << dp1[i][j] << ' ' << dp2[i][j] << ' ' << dp3[i][j] << '\n',
            dp1[i][j] = dp2[i][j] = dp3[i][j] = 0;
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}