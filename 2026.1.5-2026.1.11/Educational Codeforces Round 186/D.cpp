#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, N = 50;
int t, n, a[N + 5];
int fac[N + 5], inv[N + 5];
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
    for (int i = 1; i <= 50; i++) {
        fac[i] = 1ll * i * fac[i - 1] % MOD;
        inv[i] = qpow(fac[i], MOD - 2);
    }
    return ;
}
int c(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int ca(int n, int m) {
    return 1ll * fac[n] * inv[n - m] % MOD;
}
void solve() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i <= n; i++) cin >> a[i], sum += a[i];
    int cnt = sum / n;
    sum = sum % n;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= cnt) a[i] -= cnt;
        else a[0] -= (cnt - a[i]), a[i] = 0;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (a[i] > 1) flag = false;
    if (a[0] < 0 || !flag) cout << 0 << '\n';
    else
        cout << 1ll * c(sum, sum - a[0]) * ca(sum - a[0], sum - a[0]) % MOD * ca(n - (sum - a[0]), n - (sum - a[0])) % MOD<< '\n';
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