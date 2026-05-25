#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    int l, r;
    if (n % 2 == 1) cout << n / 2 + 1 << ' ', l = n / 2, r = n / 2 + 2;
    else l = n / 2, r = n / 2 + 1;
    int now = 0;
    while (r <= n) {
        if (!now) cout << l-- << ' ';
        else cout << r++ << ' ';
        now ^= 1;
    }
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}