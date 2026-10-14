#include <bits/stdc++.h>
using namespace std;
int t, a, b, p;
void solve() {
    cin >> a >> b >> p;
    if (b < p) cout << "Alice" << '\n';
    else if (a < p) cout << "Bob" << '\n';
    else cout << "Lasting Battle" << '\n';
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) solve();
    return 0;
}