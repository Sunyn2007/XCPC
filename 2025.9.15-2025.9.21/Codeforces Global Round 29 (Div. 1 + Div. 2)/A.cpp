#include <bits/stdc++.h>
using namespace std;
int t, x, y;
void solve() {
    cin >> x >> y;
    if (x < y) cout << 2 << '\n';
    if (x == y) cout << -1 << '\n';
    if (x > y) {
        if (x - 1 > y && y != 1) cout << 3 << '\n';
        else cout << -1 << '\n';
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