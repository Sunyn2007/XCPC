#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, dp[N + 5];
char s[3][N + 5];
void solve() {
    cin >> n >> (s[1] + 1) >> (s[2] + 1);
    for (int i = 1; i <= n; i++) dp[i] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + (s[1][i] != s[2][i]));
        if (i >= 2) dp[i] = min(dp[i], dp[i - 2] + (s[1][i] != s[1][i - 1]) + (s[2][i] != s[2][i - 1]));
    }
    cout << dp[n] << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}