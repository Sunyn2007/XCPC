#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, MOD = 1e9 + 7;
int t, n, a[N + 5], cnt[29], fac[N + 5], inv[N + 5];
int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return res;
}
void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = 1ll * fac[i - 1] * i % MOD, inv[i] = qpow(fac[i], MOD - 2);
    return ;
}
int c(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= 28; j++)
            if (cnt[j]) a[i] = (a[i] - 1ll * (1 << j) * c(cnt[j], i) % MOD + MOD) % MOD;
        for (int j = 0; j <= 28; j++)
            if ((a[i] >> j) & 1) cnt[j] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x = 0;
        for (int j = 0; j <= 28; j++)
            if (cnt[j]) x += (1 << j), cnt[j] -= 1;
        cout << x << ' ';
    }
    cout << '\n';
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