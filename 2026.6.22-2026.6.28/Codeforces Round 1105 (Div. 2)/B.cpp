#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int t, n, m, r, c;
int qpow(int x, long long y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return res;
}
void solve() {
    cin >> n >> m >> r >> c;
    cout << 1ll * qpow(qpow(2, r - 1), m - c) * qpow(qpow(2, c - 1), n - r) % MOD * qpow(2, 1ll * r * c - 1) % MOD << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}