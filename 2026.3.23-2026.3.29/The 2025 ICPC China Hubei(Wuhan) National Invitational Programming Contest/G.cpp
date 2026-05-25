#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, S = 3e5, MOD = 998244353;
int t, n, m, sz, a[S], cnt[N + 5], dp[S], ans;
int fac[N + 5], inv[N + 5];
vector<int> s;
vector<pair<int, int> > col[N + 5];
int h(int i, int j) {
    return i * (m + 1) + j + 1;
}
int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return res;
}
int add(int a, int b) {
    int res = a + b;
    if (res >= MOD) res -= MOD;
    if (res < 0) res += MOD;
    return res;
} 
void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
        inv[i] = qpow(fac[i], MOD - 2);
    }
    return ;
}
int cc(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void solve() {
    cin >> n >> m, sz = sqrt(1.0 * n * m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[h(i, j)];
            if (!cnt[a[h(i, j)]]) s.push_back(a[h(i, j)]);
            cnt[a[h(i, j)]] += 1, col[a[h(i, j)]].push_back(make_pair(i, j));
        }
    for (int k = 0; k < s.size(); k++) {
        int c = s[k];
        if (cnt[c] <= sz) {
            for (int i = 0; i < col[c].size(); i++) {
                int x = col[c][i].first, y = col[c][i].second;
                dp[i] = cc(x - 1 + y - 1, x - 1);
                for (int j = 0; j < i; j++) {
                    int xx = col[c][j].first, yy = col[c][j].second;
                    if (xx <= x && yy <= y) dp[i] = add(dp[i], -1ll * dp[j] * cc(x - xx + y - yy, x - xx) % MOD);
                }
                ans = add(ans, 1ll * dp[i] * cc(n - x + m - y, n - x) % MOD);
            }
            for (int i = 0; i < col[c].size(); i++) dp[i] = 0;
        }
        else {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++) {
                    if (i == 1 && j == 1) dp[h(i, j)] = 1;
                    else {
                        if (a[h(i - 1, j)] != c) dp[h(i, j)] = add(dp[h(i, j)], dp[h(i - 1, j)]);
                        if (a[h(i, j - 1)] != c) dp[h(i, j)] = add(dp[h(i, j)], dp[h(i, j - 1)]);
                    }
                    if (a[h(i, j)] == c) ans = add(ans, 1ll * dp[h(i, j)] * cc(n - i + m - j, n - i) % MOD);
                }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    dp[h(i, j)] = 0;
        }
        cnt[c] = 0, col[c].clear();
    }
    cout << ans << '\n';
    ans = 0, s.clear();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while (t--) solve();
    return 0;
}