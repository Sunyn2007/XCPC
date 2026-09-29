#include <bits/stdc++.h>
using namespace std;
const int N = 1e3, MOD = 998244353;
int n, a[N + 5], ans = 1, fac[N + 5];
long long sum = 0;
void init() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        int mx = a[i], mn = a[i];
        for (int j = i; j <= n; j++) {
            mx = max(mx, a[j]), mn = min(mn, a[j]);
            sum += mx - mn;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i] != a[i - 1]) {
            ans = 1ll * ans * fac[cnt] % MOD;
            cnt = 1;
        }
        else cnt += 1;
    }
    ans = 1ll * ans * fac[cnt] % MOD;
    if (a[1] != a[n]) ans = (ans << 1) % MOD;
    cout << sum << ' ' << ans;
    return 0;
}