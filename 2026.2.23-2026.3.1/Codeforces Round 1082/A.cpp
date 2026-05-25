#include <bits/stdc++.h>
using namespace std;
int t, x, y;
int syn(int x) {
    return x < 0 ? -x : x;
}
void solve() {
    cin >> x >> y;
    int xx = 0, yy = 0;
    if (y > 0) xx = y * 2, yy = y;
    if (y == 0) xx = 0, yy = 0;
    if (y < 0) xx = -y * 4, yy = y;
    if (xx <= x && (x - xx) % 3 == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}