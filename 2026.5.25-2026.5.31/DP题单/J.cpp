#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 10, M = 1 << 10;
int t, n, m, v[N + 5], w[N + 5];
bitset<M + 5> dp[2][M + 5];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    int tag = 0;
    dp[tag][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < N; j++)
            dp[tag ^ 1][j] = dp[tag][j] | (dp[tag][j ^ w[i]] << v[i]);
        tag ^= 1;
    }
    int ans = -1;
    for (int i = 0; i < N; i++)
        if (dp[tag][i][m]) ans = i;
    cout << ans << '\n';
    for (int i = 0; i < N; i++) 
        dp[0][i].reset(), dp[1][i].reset();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}