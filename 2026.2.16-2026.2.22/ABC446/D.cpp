#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n, a[N + 5], ans;
map<int, int> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[a[i]] = dp[a[i] - 1] + 1;
        ans = max(ans, dp[a[i]]);
    }
    cout << ans;
    return 0;
}