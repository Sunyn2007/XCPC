#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, a[N + 5];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
    bool ok = true;
    for (int i = 3; i <= n; i++)
        if (a[i] != a[i - 2] % a[i - 1]) ok = false;
    if (ok) cout << a[1] << ' ' << a[2] << '\n';
    else cout << -1 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}