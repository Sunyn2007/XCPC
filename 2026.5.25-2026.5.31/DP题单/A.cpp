#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int t, n, k;
long long dp[4 * N + 5];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) dp[i] = 1e18;
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = k; j >= 1; j--) {
            dp[j] = min(dp[j], dp[j - 1] + a);
            dp[j] = min(dp[j], dp[j - 2] + b);
            dp[j] = min(dp[j], dp[j - 3] + c);
            dp[j] = min(dp[j], dp[j - 4] + d);
        }   
    }
    cout << dp[k] << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}