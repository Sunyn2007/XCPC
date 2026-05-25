#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, h[N + 5];
long long sum[N + 5], dp[N + 5], minn;
void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> h[i], sum[i] = sum[i - 1] + h[i];
    dp[n] = h[n], minn = sum[n] - (n + 1);
    for (int i = n - 1; i >= 1; i--) {
        dp[i] = minn + h[i] + max(0, h[i + 1] - i) - sum[i + 1] + i + 2;
        minn = min(minn, dp[i + 1] + sum[i] - (i + 1));
    }
    cout << dp[1] << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve(); 
    return 0;
}
/*
f[i] = min{f[j] + sum[j - 1] + a[i] + max(0, a[i + 1] - i) - sum[i + 1] - j + i + 2}
f[i] = min{f[j] + a[i] + max(0, a[i + 1] - i) + sum[j - 1] - sum[i + 1] - j + i + 2}
*/