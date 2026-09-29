#include <bits/stdc++.h>
using namespace std;
const int N = 16;
int t, n;
string g[N + 5], w[N + 5];
bool dp[1 << N][N + 5], ok[N + 5][N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> g[i] >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) ok[i][j] = (w[i] == w[j] || g[i] == g[j]);
    for (int msk = 0; msk < (1 << n); msk++) 
        for (int i = 1; i <= n; i++) 
            if ((msk >> i - 1) & 1) {
                if ((msk ^ (1 << i - 1)) == 0) dp[msk][i] = true;
                else {
                    for (int j = 1; j <= n; j++)
                        if (j != i && ((msk >> j - 1) & 1) && ok[i][j]) 
                            dp[msk][i] |= dp[msk ^ (1 << i - 1)][j];
                }
            }
    int ans = n;
    for (int msk = 0; msk < (1 << n); msk++) {
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (!((msk >> i - 1) & 1)) res += 1;
        for (int i = 1; i <= n; i++)
            if (dp[msk][i]) ans = min(ans, res), dp[msk][i] = false;
    }
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