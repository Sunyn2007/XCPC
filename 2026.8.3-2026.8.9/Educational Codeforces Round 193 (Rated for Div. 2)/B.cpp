#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, a[N + 5], tot;
int calc(int i) {
    int res = tot;
    if (i > 1 && a[i] != a[i - 1]) res -= 1;
    if (i + 1 < n && a[i + 1] != a[i + 2]) res -= 1;
    if (i > 1 && a[i + 1] != a[i - 1]) res += 1;
    if (i + 1 < n && a[i] != a[i + 2]) res += 1;
    return res;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    tot = 0;
    for (int i = 1; i <= n; i++)
        if (i == 1 || a[i] != a[i - 1]) tot += 1;
    int ans = tot;
    for (int i = 1; i < n; i++)
        ans = max(ans, calc(i));
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