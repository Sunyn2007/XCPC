#include <bits/stdc++.h>
using namespace std;
int t;
long long s, m;
bool check(long long x) {
    long long ts = s, tm = m;
    for (int i = 62; i >= 0; i--)
        if ((tm >> i) & 1) {
            long long d = 1ll << i;
            if (ts / d > x) ts -= x * d;
            else ts -= ts / d * d;
        }
    return ts == 0;
}
void solve() {
    cin >> s >> m;
    long long l = 1, r = 1e18, ans = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
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