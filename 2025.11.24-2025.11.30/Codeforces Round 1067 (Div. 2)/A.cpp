#include <bits/stdc++.h>
using namespace std;
int t, n, x, y;
void solve() {
    cin >> n >> x >> y;
    cout << min(n, (x / 2) + y) << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}