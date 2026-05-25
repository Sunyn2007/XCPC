#include <bits/stdc++.h>
using namespace std;
int t, p, q;
void solve() {
    cin >> p >> q;
    int tot = p + 2 * q, n = 1, m;
    while (2ll * n * (n + 1) <= tot) {
        if ((tot - n) % (2 * n + 1) == 0) {
            m = (tot - n) / (2 * n + 1);
            if (2 * q <= 2 * n * (n + 1) + 2 * (m - n) * n) {
                cout << n << ' ' << m << '\n';
                return ;
            }
        }
        n += 1;
    }
    cout << -1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}