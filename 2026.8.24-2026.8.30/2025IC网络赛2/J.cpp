#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long i64;
typedef std::vector<int> veci;
typedef std::vector<i64> veci64;
typedef std::vector<veci> Graph;

const i64 MOD = 998244353;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<veci> pr(n + 2);
    veci vis(n + 2);
    veci node;
    for (int i = 1; i <= m; ++i) {
        int x, y;scanf("%d%d", &x, &y);
        if(x > y)
            std::swap(x, y);
        // x < y
        pr[x].emplace_back(y);
        pr[y].emplace_back(x);
        vis[x] = -1;
        vis[y] = -1;
    }
    veci tmpvis(n + 2);
    int tot = 0;
    for (int x = 1; x <= n; ++x) {
        if(x != -1)
            continue;
        ++tot;
        for (auto y : pr[x]) {
            tmpvis[y] = 1;
        }

        for ()
        
        for (auto y : pr[x]) {
            tmpvis[y] = 0;
        }
    }
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }

    return 0;
}