#include <bits/stdc++.h>
using namespace std;
int t, x, y, z, a, b, c;
void solve() {
    cin >> x >> y >> z;
    a = x | z, b = x | y, c = y | z;
    if ((a & b) != x || (b & c) != y || (a & c) != z) cout << "No" << '\n';
    else cout << "Yes" << "\n";
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}