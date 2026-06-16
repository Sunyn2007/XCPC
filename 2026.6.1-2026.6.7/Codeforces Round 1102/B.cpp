#include <bits/stdc++.h>
using namespace std;
int t;
long long n, y;
void solve() {
    cin >> n;
    y = n % 12;
    if (y <= 9 || y == 11) cout << y << ' ' << n - y << '\n';
    else {
        if (n >= 22) cout << 22 << ' ' << n - 22 << '\n';
        else cout << -1 << '\n';
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