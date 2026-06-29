#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, d, a[N + 5], b[N * 3 + 5];
long long pre[N * 3 + 5];
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= 3 * n; i++) {
        b[i] = a[(i - 1) % n + 1];
        pre[i] = pre[i - 1] + b[i];
    }
    long long ans = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
        long long view = pre[i + d] - pre[i] + pre[i - 1] - pre[i - d - 1];
        long long w = 2ll * d * b[i] - view;
        if (w > 0) ans += w;
    }
    cout << ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}