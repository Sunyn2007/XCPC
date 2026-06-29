#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 1e6;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s ^= a[i];
    if (n == 1) cout << 0 << '\n';
    else if (s == 0) cout << 1 << '\n';
    else {
        int mx = 0, ans = 0;
        for (int i = 30; i >= 1; i--) 
            if ((s >> i - 1) & 1) {
                mx = i;
                break;
            }
        for (int i = 1; i <= n; i++)
            if ((a[i] >> mx - 1) & 1) ans += 1;
        cout << ans << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}