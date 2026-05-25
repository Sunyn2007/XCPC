#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t, n, a[N], b[N];
bool check(int k) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (k - 1 - cnt <= a[i] && cnt <= b[i]) cnt++;
    }
    return cnt >= k;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}