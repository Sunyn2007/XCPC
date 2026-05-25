#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, MOD = 1e6 + 3;
int t, n, a[N + 5], b[N + 5], book[N + 5][21];
long long tot[21];
int fac[MOD + 5], inv[MOD + 5];
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
    for (int i = 1; i < MOD; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
        inv[i] = qpow(fac[i], MOD - 2);
    }
    return ;
}
int c(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int mink = 20;
    for (int i = 1; i <= n; i++) {
        int tmp = a[i], k = 0;
        while ((tmp << 1) <= b[i]) 
            tmp <<= 1, k += 1;
        mink = min(mink, k);
    }
    long long ans1 = mink;
    int ans2 = 1;
    for (int i = 1; i <= n; i++) {
        int tmp = b[i] - (a[i] << mink);
        for (int j = mink; j >= 0; j--) {
            int cnt = tmp / (1 << j);
            book[i][j] += cnt, tot[j] += cnt;
            ans1 += cnt;
            tmp -= cnt * (1 << j);
        }
    } 
    for (int i = mink; i >= 0; i--) {
        if (tot[i] >= MOD) {
            ans2 = 0;
            break;
        }
        int tmp = 1;
        for (int j = 1; j <= n; j++) {
            tmp = 1ll * tmp * c(tot[i], book[j][i]) % MOD;
            tot[i] -= book[j][i];
        }
        ans2 = 1ll * ans2 * tmp % MOD;
    }
    cout << ans1 << ' ' << ans2 << '\n';
    for (int i = 0; i <= mink; i++) {
        tot[i] = 0;
        for (int j = 1; j <= n; j++)
            book[j][i] = 0;
    }
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