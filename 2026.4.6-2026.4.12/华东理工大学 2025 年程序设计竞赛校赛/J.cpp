#include <bits/stdc++.h>
using namespace std;
int t, n, a, d, m, k;
void solve() {
    cin >> n >> a >> d >> m >> k;
    int ans = 1 + m;
    if (d > k) {
        if (k == 0) ans += n - 1;
        else {
            int cnt;
            if (d % k == 0) cnt = d / k - 1;
            else cnt = d / k;
            if (m / cnt < n - 1) ans += n - 1 - m / cnt;
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