#include <bits/stdc++.h>
using namespace std;
int t, n, m, d;
void solve() {
    cin >> n >> m >> d;
    if (n % (d / m + 1) == 0) cout << n / (d / m + 1);
    else cout << n / (d / m + 1) + 1;
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