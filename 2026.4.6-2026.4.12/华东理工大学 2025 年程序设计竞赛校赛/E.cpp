#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n;
long long x, y, a[N + 5], s[N + 5];
void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int sta = (x >= 0) + (y >= 0);
    long long ans = 0;
    if (sta == 2) {
        if (x < y) swap(x, y);
        for (int i = 1; 2 * i <= n; i++)
            ans = max(ans, x * (s[n] - s[n - i]) + y * (s[n - i] - s[n - 2 * i]));
    }
    if (sta == 1) {
        if (x < y) swap(x, y);
        for (int i = 1; 2 * i <= n; i++)
            ans = max(ans, x * (s[n] - s[n - i]) + y * s[i]);
    }
    if (sta == 0) {
        if (x > y) swap(x, y);
        for (int i = 1; 2 * i <= n; i++)
            ans = max(ans, x * s[i] + y * (s[2 * i] - s[i]));
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