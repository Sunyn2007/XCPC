#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5];
long long s[N + 5];
bool check(int p, int x) {
    if (1ll * (x - 1) * k >= p - 1) return false;
    int l = (x - 1) * k + 1, r = min(x * k, p - 1);
    long long det1 = 1ll * (r - l + 1) * a[p] - (s[r] - s[l - 1]);
    long long det2 = a[p + x] - a[p];
    return det1 - det2 >= 0;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    long long ans = s[n];
    for (int i = 2; i <= n - 1; i++) {
        int l = 1, r = min(i - 1, n - i), res = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        if (res) {
            int cnt = min(1ll * i - 1, 1ll * res * k);
            long long det1 = 1ll * a[i] * cnt - s[cnt];
            long long det2 = s[i + res] - s[i] - 1ll * res * a[i];
            ans = max(ans, s[n] + det1 - det2);
        } 
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