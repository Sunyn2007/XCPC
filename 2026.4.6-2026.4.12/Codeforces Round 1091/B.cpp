#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, k, a[N + 5], p;
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> p;
    int l = 1, r = n, tag = 0, x = a[p], ans = 0;
    while (l != p || r != p) {
        if (l != p && r != p) {
            if (a[l] == a[r]) {
                if (a[l] ^ tag != x) ans += 1, tag ^= 1;
                l += 1, r -= 1;
            }
            else {
                if (a[l] ^ tag == x) l += 1;
                else r -= 1;
            }
        }
        else if (l != p) {
            if (a[l] ^ tag != x) ans += 1, tag ^= 1;
            l += 1;
        }
        else {
            if (a[r] ^ tag != x) ans += 1, tag ^= 1;
            r -= 1;
        }
    }
    if (a[p] ^ tag != x) ans += 1;
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