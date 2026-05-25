#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d;
void solve() {
    cin >> a >> b >> c >> d;
    c -= a, d -= b;
    if (a - b * 2 >= 3 || b - a * 2 >= 3 || c - d * 2 >= 3 || d - c * 2 >= 3) cout << "No" << '\n';
    else cout << "Yes" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}