#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    if (n % 3 == 0) cout << 0 << '\n';
    else cout << 3 - n % 3 << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}