#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2e6 + 4 + 5;
const long long INF = 0x7fffffffffffffff;
int t, n, m, a[N];
long long pre[N], suf[N], s[N], d[N], u[N];
int hsh(int x, int y) {
    return x * (m + 1) + y + 1;
}
void init() {
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            pre[hsh(i, j)] = suf[hsh(i, j)] = u[hsh(i, j)] = d[hsh(i, j)] = -INF;
    return ;
}
void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[hsh(i, j)];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) pre[hsh(i, j)] = a[hsh(i, j)];
            else pre[hsh(i, j)] = max(pre[hsh(i, j - 1)], pre[hsh(i - 1, j)]) + a[hsh(i, j)];
        }
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--) {
            if (i == n && j == m) suf[hsh(i, j)] = a[hsh(i, j)];
            else suf[hsh(i, j)] = max(suf[hsh(i + 1, j)], suf[hsh(i, j + 1)]) + a[hsh(i, j)];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[hsh(i, j)] = pre[hsh(i, j)] + suf[hsh(i, j)] - a[hsh(i, j)];
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            u[hsh(j, i)] = max(u[hsh(j - 1, i)], s[hsh(j, i)]);
        for (int j = n; j >= 1; j--)
            d[hsh(j, i)] = max(d[hsh(j + 1, i)], s[hsh(j, i)]);
    }
    long long ans = INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            long long res = s[hsh(i, j)] - 2 * a[hsh(i, j)];
            res = max(res, u[hsh(i - 1, j + 1)]);
            res = max(res, d[hsh(i + 1, j - 1)]);
            ans = min(ans, res);
        }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}