#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
int t, n, m, a[N + 5], b[N + 5], dp[N + 5], s[N + 5], tot[N + 5];
bool ok[N + 5];
int syn(int x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    m = b[(1 + n) / 2];
    for (int i = 1; i <= n; i++) {
        tot[i] = tot[i - 1];
        s[i] = s[i - 1];
        if (a[i] == m) tot[i] += 1;
        if (a[i] < m) s[i] -= 1;
        if (a[i] > m) s[i] += 1;
    }
    for (int i = 1; i <= n; i++) dp[i] = ok[i] = 0;
    ok[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j -= 2) {
            int len = i - j + 1, cnt = tot[i] - tot[j - 1], sum = s[i] - s[j - 1];
            if (!cnt || !ok[j - 1]) continue;
            int x = (len - cnt - syn(sum)) / 2;
            if (x <= len / 2 && x + cnt > len / 2) ok[i] = true, dp[i] = max(dp[i], dp[j - 1] + 1);
        }
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