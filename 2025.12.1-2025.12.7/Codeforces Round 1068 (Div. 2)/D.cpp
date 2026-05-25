#include <bits/stdc++.h>
using namespace std;
int t, n, k, s[35], dp[35][35];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= 30; i++) {
        s[i] = s[i - 1];
        if ((n >> i - 1) & 1) s[i] += 1;
    }
    if (30 - s[30] + 1 > k) {
        for (int i = 1; i <= 30; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int l = 0; l < i; l++) {
                    int c = (i - l) - (s[i] - s[l]) + 1;
                    if (c <= j) dp[i][j] = max(dp[i][j], dp[l][j - c] + (i - l));
                }
            }   
        }
        cout << dp[30][k] << '\n';
        for (int i = 1; i <= 30; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = 0;
    }
    else cout << s[30] + k - 1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}
/*
30位
dp[i][j]
前i位用了j获得的最多进位
*/