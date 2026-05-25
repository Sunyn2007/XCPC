#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], book[N + 5], dp[N + 5], lst[N + 5], nxt[N + 5], p[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!p[a[i]]) p[a[i]] = i;
        nxt[lst[a[i]]] = i;
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        book[a[i]] += 1;
        if (book[a[i]] >= a[i]) {
            dp[i] = max(dp[i], dp[p[a[i]] - 1] + a[i]);
            p[a[i]] = nxt[p[a[i]]];
        }
    }
    cout << dp[n] << '\n';
    for (int i = 1; i <= n; i++) 
        book[i] = p[i] = lst[i] = nxt[i] = 0;
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}