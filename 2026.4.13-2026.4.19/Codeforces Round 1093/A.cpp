#include <bits/stdc++.h>
using namespace std;
int t, n, a[205];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    bool ok = true;
    for (int i = 2; i <= n; i++)
        if (a[i] == a[i - 1]) ok = false;
    if (ok) {
        for (int i = n; i >= 1; i--)
            cout << a[i] << ' ';
        cout << '\n';
    }
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