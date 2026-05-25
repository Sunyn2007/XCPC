#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, len, a[N + 5];
priority_queue<int> q;
void solve() {
    cin >> n >> k >> len;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) q.push(a[i] - a[i - 1]);
    int l = a[1] - 0, r = len - a[n], tmp = 0;
    long long ans = max(l, r) + 1ll * (k - 1) * (l + r);
    while (k && !q.empty()) {
        int d = q.top();
        q.pop(), k -= 1;
        l += d / 2, r += d / 2, tmp += d / 2;
        if (k) ans = max(ans, tmp + max(l, r) + 1ll * (k - 1) * (l + r));
        else ans = max(ans, 1ll * tmp);
    }
    cout << ans << '\n';
    while (!q.empty()) q.pop();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}