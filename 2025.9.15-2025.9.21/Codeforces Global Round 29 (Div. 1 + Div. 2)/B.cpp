#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    for (int i = n; i >= 1; i--) cout << i << ' ';
    cout << n << ' ';
    for (int i = 1; i <= n - 1; i++) cout << i << ' ';
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