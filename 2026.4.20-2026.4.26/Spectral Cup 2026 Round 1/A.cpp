#include <bits/stdc++.h>
using namespace std;
int t, n, a[105];
bool dp[1005];
void solve() {
    cin >> n;
    for (int i = 0; i <= 100 * n; i++) dp[i] = false;
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++)
            for (int k = 100 * n; k >= 0; k--)
                if (k >= 100 / a[i]) dp[k] |= dp[k - 100 / a[i]];
    }
    bool ans = true;
    for (int i = 0; i <= 100 * n; i++) 
        if (!dp[i]) ans = false;
    if (ans) cout << "Yes" << '\n';
    else cout << "No" << "\n";
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}