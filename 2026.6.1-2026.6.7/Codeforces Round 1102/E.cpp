#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, MOD = 1e9 + 7;
int t, n, ans;
long long a[N + 5];
int fac[N + 5], inv[N + 5];
bool ok;
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
    for (int i = 1; i <= N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
        inv[i] = qpow(fac[i], MOD - 2);
    }
    return ;
}
int c(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void calc(int l, int r) {
    if (l == r) {
        if (a[l] != 1) ok = false;
        return ;
    }
    int tl = l, tr = r, p = 0;
    while (tl <= tr) {
        if (tl - l <= r - tr) {
            if (a[tl] == 1ll * (r - tl + 1) * (tl - l + 1)) {
                p = tl;
                break;
            }
            else tl += 1;
        }
        else {
            if (a[tr] == 1ll * (r - tr + 1) * (tr - l + 1)) {
                p = tr;
                break;
            }
            else tr -= 1;
        }
    }
    if (!p) {
        ok = false;
        return ;
    }
    else {
        ans = 1ll * ans * c(r - l, p - l) % MOD;
        if (p > l) calc(l, p - 1);
        if (p < r) calc(p + 1, r);
        return ;
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ok = true, ans = 1;
    calc(1, n);
    if (ok) cout << ans << '\n';
    else cout << 0 << '\n';
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