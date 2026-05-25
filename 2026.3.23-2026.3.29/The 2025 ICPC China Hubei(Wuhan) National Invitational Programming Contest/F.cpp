#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, MOD = 998244353;
int t, n, m, tot;
struct syn {
    long long a;
    int b;
}a[N + 5], b[N + 5];
bool cmp(syn a, syn b) {
    return a.b > b.b;
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
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b;
    sort(a + 1, a + n + 1, cmp);
    tot = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].b != a[i - 1].b) b[++tot] = a[i];
        else b[tot].a += a[i].a;
    }
    int p = 1, nowk = 0, ans = 0;
    __int128 nowc = 0;
    while (p <= tot) {
        if (!nowc) {
            int cnt = ((b[p].a - 1) / m + 1) % MOD;
            ans = (ans + 1ll * qpow(2, b[p].b) * cnt % MOD) % MOD;
            b[p].a %= m;
            if (b[p].a) nowc = m - b[p].a, nowk = 0;
            p += 1;
        }
        else {
            nowk += b[p - 1].b - b[p].b;
            if (nowk >= 48 || nowc * (1ll << nowk) >= 2e14) break;
            nowc *= (1ll << nowk), nowk = 0;
            if (nowc < b[p].a) b[p].a -= nowc, nowc = 0;
            else {
                nowc -= b[p].a, b[p].a = 0;
                p += 1;
            }
        }
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