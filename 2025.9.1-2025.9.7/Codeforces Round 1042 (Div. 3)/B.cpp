#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) cout << -1 << ' ';
        else {
            if (i == n) cout << 2 << ' ';
            else cout << 3 << ' ';
        }
    }
    cout << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}