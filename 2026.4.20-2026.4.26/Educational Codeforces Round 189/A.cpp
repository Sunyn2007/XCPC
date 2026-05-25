#include <bits/stdc++.h>
using namespace std;
int t;
long long x, y;
void solve() {
    cin >> x >> y;
    if (y / x == 2) cout << "NO" << '\n';
    else cout << "YES" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}