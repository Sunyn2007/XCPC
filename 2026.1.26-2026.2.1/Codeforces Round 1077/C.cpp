#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, INF = 0x7fffffff;
int t, n, minv, maxv, a[N + 5], s[N + 5];
bool check(int k) {
    for (int i = 1; i <= n; i++)
        if (a[i] - minv < k && maxv - a[i] < k && a[i] != s[i]) return false;
    return true;
}
void solve() {
    cin >> n;
    minv = INF, maxv = -INF;
    for (int i = 1; i <= n; i++) 
        cin >> a[i], s[i] = a[i], minv = min(minv, a[i]), maxv = max(maxv, a[i]);
    sort(s + 1, s + n + 1);
    int l = 0, r = maxv - minv + 1, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    if (ans < maxv - minv + 1)cout << ans << '\n';
    else cout << -1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}