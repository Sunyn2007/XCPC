#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, K = 1e9, MOD = 1e9 + 7;
int t, n, k, a[N + 5], cnt[35];
long long ans, mul[35];
void pre() {
    cnt[1] = 1, mul[0] = mul[1] = 1;
    int now = 1;
    while (cnt[now] < K) {
        now += 1;
        cnt[now] = (cnt[now - 1] << 1) + 1;
        mul[now] = mul[now - 1] * mul[now - 1] % MOD * now % MOD;
    }
    return ;
}
void syn(int s, int k) {
    if (s == 0 || k == 0) return ;
    if (k <= cnt[s - 1]) syn(s - 1, k);
    else {
        ans = ans * mul[s - 1] % MOD * s % MOD;
        k -= cnt[s - 1] + 1;
        syn(s - 1, k);
    }
    return ;
}
void solve() {
    ans = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        k -= 1;
        ans = ans * a[i] % MOD;
        int s = min(30, a[i] - 1);
        if (k > cnt[s]) k -= cnt[s], ans = ans * mul[s] % MOD;
        else {
            syn(s, k);
            break;
        }
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> t;
    while (t--) solve();
    return 0;
}