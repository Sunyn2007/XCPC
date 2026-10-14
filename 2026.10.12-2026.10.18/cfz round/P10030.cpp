#include <bits/stdc++.h>
using namespace std;
int t, p, a, b, c;
void solve() {
    cin >> p >> a >> b >> c;
    if (b == 0) {
        if (c) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
    else cout << "Yes" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}