#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int a, b, k, t1 = 0, t2 = 0, ans = 0;
int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % MOD;
        x = 1ll * x * x % MOD;
        y >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> k;
    while (t1 <= k || t2 <= k) {
        if (t1 == t2) t1 += a, t2 += b;
        else if (t1 < t2) ans += 1, t1 += a;
        else ans = max(0, ans - 1), t2 += b;
    }
    cout << qpow(2, ans);
    return 0;
}