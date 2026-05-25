#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n;
double c[N + 5], p[N + 5], dp[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i] >> p[i], p[i] /= 100.0;
    for (int i = n; i >= 1; i--)
        dp[i] = max(dp[i + 1], c[i] + dp[i + 1] * (1 - p[i]));
    cout << fixed << setprecision(10) << dp[1] << '\n';
    for (int i = 1; i <= n; i++) dp[i] = 0.0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}