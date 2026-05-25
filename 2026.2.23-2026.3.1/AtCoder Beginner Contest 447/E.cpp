#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 2e5, MOD = 998244353;
int n, m, u[N + 5], v[N + 5], cnt, ans, tot, tmp, fa[N + 5], p[M + 5];
void init() {
    p[0] = 1;
    for (int i = 1; i <= M; i++)
        p[i] = (p[i - 1] << 1) % MOD;
    return ;
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return ;
    fa[y] = x;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) cin >> u[i] >> v[i];
    for (int i = m; i >= 1; i--) {
        tot = (tot + p[i]) % MOD;
        if (find(u[i]) == find(v[i])) tmp = (tmp + p[i]) % MOD;
        else if (cnt < n - 2) merge(u[i], v[i]), cnt += 1, tmp = (tmp + p[i]) % MOD;
    }
    ans = (tot - tmp + MOD) % MOD;
    cout << ans;
    return 0;
}