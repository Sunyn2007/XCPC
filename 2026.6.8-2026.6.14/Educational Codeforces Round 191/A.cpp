#include <bits/stdc++.h>
using namespace std;
int t, n, x, y, z;
void solve() {
    cin >> n >> x >> y >> z;
    int t1 = (n - 1) / (x + y) + 1;
    int t2;
    if (z * x >= n) t2 = (n - 1) / x + 1;
    else t2 = z + (n - z * x - 1) / (x + 10 * y) + 1;
    cout << min(t1, t2) << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}