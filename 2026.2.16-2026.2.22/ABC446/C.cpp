#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, d, n, a[N + 5], b[N + 5];
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    int now = 1;
    for (int i = 1; i <= n; i++) {
        while (b[i]) {
            if (a[now] > b[i]) a[now] -= b[i], b[i] = 0;
            else b[i] -= a[now], a[now] = 0, now += 1;
        }
        if (i - d == now) a[now] = 0, now += 1;
    }
    int ans = 0;
    for (int i = now; i <= n; i++)
        ans += a[i];
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