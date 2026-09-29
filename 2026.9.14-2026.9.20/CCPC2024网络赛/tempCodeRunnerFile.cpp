#include <bits/stdc++.h>
using namespace std;
const int N = 500, M = 500, MOD = 998244353;
int n, m, a[N + 5], b[N + 5], deg[N + 5], dp[N + 5], sum, ans;
vector<int> e[505];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (b[j] >= a[i]) e[b[j] - a[i]].push_back(i);
    for (int i = 499; i >= 0; i--)
        if (!e[i].empty()) {
            for (auto x : e[i]) deg[x] += 1;
            for (int j = 0; j <= n; j++) dp[j] = 0;
            dp[0] = 1;
            for (int j = n; j >= 1; j--) {
                for (int k = n - j + 1; k >= 1; k--)
                    if (deg[j] >= k)
                        dp[k] = (dp[k] + 1ll * dp[k - 1] * (deg[j] - (k - 1)) % MOD) % MOD;
            }
            int tot = 0;
            for (int j = 1; j <= n; j++) 
                tot = (tot + dp[j]) % MOD;
            ans = (ans + 1ll * (tot - sum) * i % MOD) % MOD;
            sum = tot;
        }
    cout << ans;
    return 0;
}