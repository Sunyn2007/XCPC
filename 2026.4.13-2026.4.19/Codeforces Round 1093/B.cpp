#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int t, n, m, a[N + 5];
void solve() {
    cin >> n >> m;
    int mx = 0, len = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1 || a[i] != a[i - 1]) len = 1;
        else len += 1;
        mx = max(mx, len);
    }
    if (mx >= m) cout << "NO" << '\n';
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