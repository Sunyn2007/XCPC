#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, MOD = 998244353;
int t, n;
long long a[N + 5], x;
void solve() {
    cin >> n >> x;
    if (x == 1) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) 
            cin >> a[i], ans = (ans + a[i]) % MOD;
        cout << ans << '\n';
        return ;
    }
    __int128 cnt = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], cnt += a[i] / x, a[i] %= x;
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) {
        if (cnt >= (x - a[i] - 1))
            cnt -= x - a[i] - 1;
        else ans = (ans + a[i]) % MOD;
    }
    cnt %= (x - 1);
    ans = (ans + cnt % MOD) % MOD;
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