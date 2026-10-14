#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    if (n == 3) cout << "1 -10 6 6 -10 1" << '\n';
    else {
        cout << 1 << ' ';
        for (int i = 1; i <= n - 1; i++) cout << "2 -1 ";
        cout << -n + 3 << '\n';
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}