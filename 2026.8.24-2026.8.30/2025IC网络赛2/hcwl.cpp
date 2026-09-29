#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::vector<veci> Graph;

const i64 MOD = 998244353;

i64 jc[3010];
void init() {
    jc[0] = 1;
    for (int i = 1; i < 3010; ++i)
        jc[i] = jc[i - 1] * i % MOD;
}

void dfs1(int x, int faa, const Graph& g, veci &dp, veci& leaf) {
    if(leaf[x])
        dp[x] = 1;
    for(auto y : g[x]) {
        if(y == faa)
            continue;
        dfs1(y, x, g, dp, leaf);
        dp[x] += dp[y];
    }
}

void dfs2(int x, int faa, const Graph& g, int len, int rt, i64 &ans) {
    i64 tmp = jc[len - 2] * (len - 2ll) * (len - 2ll) % MOD;
    tmp = (tmp + jc[len - 1]) % MOD;
    if(x > rt)
        ans = (ans + tmp) % MOD;
    for (auto y : g[x]) {
        if(y == faa)
            continue;
        dfs2(y, x, g, len + 1, rt, ans);
    }
}

void solve() {
    int n;scanf("%d", &n);
    Graph g(n + 2);
    veci dgr(n + 2);
    for (int i = 1; i < n; ++i) {
        int x, y;scanf("%d%d", &x, &y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        ++dgr[x];
        ++dgr[y];
    }
    i64 ans = 0;
    for (int rt = 1; rt <= n; ++rt) {
        for (auto y : g[rt]) {
            dfs2(y, rt, g, 2, rt, ans);
        }
    }
    ans = (ans + 1) % MOD;
    printf("%lld\n", ans);
}

int main() {
    init();
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}