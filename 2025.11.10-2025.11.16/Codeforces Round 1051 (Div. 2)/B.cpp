#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, K = 2e5;
int t, n, k, a[N + 5], b[K + 5];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];
    sort(a + 1, a + n + 1), sort(b + 1, b + k + 1);
    long long ans = 0;
    int now = n;
    for (int i = 1; i <= k; i++) {
        if (now < b[i]) break;
        while (b[i]) {
            if (b[i] > 1) ans += a[now];
            b[i] -= 1, now -= 1;
        }
    }
    while (now) ans += a[now--];
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