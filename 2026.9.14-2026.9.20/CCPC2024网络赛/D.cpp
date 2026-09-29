#include <bits/stdc++.h>
using namespace std;
const int N = 100, M = 100, MOD = 998244353;
int n, m, dp[N + 5][M + 5][M + 5];
string s, t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t, n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= m; l++)
            for (int r = l; r <= m; r++) {
                dp[i][l][r] = (dp[i][l][r] + (dp[i - 1][l][r] << 1) % MOD) % MOD;
                for (int k = l; k < r; k++) dp[i][l][r] = (dp[i][l][r] + 1ll * dp[i - 1][l][k] * dp[i - 1][k + 1][r] % MOD) % MOD;
                for (int k = l + 1; k < r; k++) if (s[i] == t[k]) dp[i][l][r] = (dp[i][l][r] + 1ll * dp[i - 1][l][k - 1] * dp[i - 1][k + 1][r] % MOD) % MOD;
                if (l == r) {
                    if (s[i] == t[l]) dp[i][l][r] = (dp[i][l][r] + 1) % MOD;
                }
                else {
                    if (s[i] == t[l]) dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l + 1][r]) % MOD;
                    if (s[i] == t[r]) dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][r - 1]) % MOD;
                }
            }
    }
    cout << dp[n][1][m];
    return 0; 
}