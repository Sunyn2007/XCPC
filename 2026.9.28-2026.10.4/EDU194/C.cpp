#include <bits/stdc++.h>
using namespace std;
int t, x, y;
void solve() {
    cin >> x >> y;
    int s = x + y, ans = 0;
    for (int i = 30; i >= 1; i--)
        if (((s >> i - 1) & 1) && ans + (1 << i - 1) <= x) ans += (1 << i - 1);
    cout << x + y << ' ' << x - ans << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}