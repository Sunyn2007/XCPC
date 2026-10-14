#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int t, n, a[N + 5], dp[N + 5][N + 5][2][2];
string s;
void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) a[i + 1] = (s[i] == ')');
    int mn0 = 0, mx1 = 0;
    for (int i = 1; i <= n; i++) if (a[i] == 0) {mn0 = i; break;}
    for (int i = n; i >= 1; i--) if (a[i] == 1) {mx1 = i; break;}
    for (int i = 1; i < n; i++) if (a[i] == a[i + 1]) dp[i][i + 1][1][a[i]] = 2;
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j][0][0] = max(dp[i + 1][j][0][0], dp[i][j - 1][0][0]);
            dp[i][j][0][1] = max(dp[i + 1][j][0][1], dp[i][j - 1][0][1]);
            dp[i][j][1][0] = max(dp[i + 1][j][1][0], dp[i][j - 1][1][0]);
            dp[i][j][1][1] = max(dp[i + 1][j][1][1], dp[i][j - 1][1][1]);
            if (a[i] == a[j]) {
                dp[i][j][1][a[i]] = max(dp[i][j][1][a[i]], max(dp[i + 1][j - 1][0][a[i]], dp[i + 1][j - 1][0][!a[i]]) + 2);
                if (dp[i + 1][j - 1][1][!a[i]]) dp[i][j][0][a[i]] = max(dp[i][j][0][a[i]], dp[i + 1][j - 1][1][!a[i]] + 2);
            }
        }
    }
    if (mn0 && mx1 && mn0 < mx1) {
        int ans = 2;
        for (int i = mn0 + 1; i < mx1; i++)
            for (int j = i + 1; j < mx1; j++)
                ans = max(ans, max(dp[i][j][0][0], dp[i][j][0][1]) + 2);
        cout << ans << '\n';
    }
    else cout << 0 << '\n';
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j][0][0] = dp[i][j][0][1] = dp[i][j][1][0] = dp[i][j][1][1] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}