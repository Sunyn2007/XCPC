#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    n -= 1;
    cout << 0 << ' ';
    for (int i = 1; i <= n / 2; i++)
        cout << i << ' ' << -i << ' ';
    if (n % 2 == 1) cout << n / 2 + 1 << ' ';
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