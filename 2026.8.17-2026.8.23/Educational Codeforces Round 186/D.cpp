#include <bits/stdc++.h>
using namespace std;
const int N = 50, MOD = 998244353;
int t, n, a[N + 5], fac[N + 5], inv[N + 5];
int qpow(int x, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        k >>= 1;
    }
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
int ca(int n, int m) {
    return 1ll * fac[n] * inv[n - m] % MOD;
}
int cc(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void solve() {
    cin >> n;
    int sum = 0, rd, ans;
    for (int i = 0; i <= n; i++) cin >> a[i], sum += a[i];
    if (sum % n == 0) {
        rd = sum / n;
        bool fl = true;
        for (int i = 1; i <= n; i++) 
            if (a[i] > rd) fl = false;
        if (fl) ans = ca(n, n);
        else ans = 0;
    }
    else {
        rd = sum / n, sum %= n;
        bool fl = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] > rd + 1) fl = false;
            else if (a[i] >= rd) a[i] -= rd;
            else a[0] -= rd - a[i], a[i] = 0;
        }
        if (fl) ans = 1ll * cc(sum, a[0]) * ca(n - (sum - a[0]), n - (sum - a[0])) % MOD * ca(sum - a[0], sum - a[0]) % MOD;
        else ans = 0;
    }
    cout << ans << '\n';
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