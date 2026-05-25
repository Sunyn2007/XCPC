#include <bits/stdc++.h>
using namespace std;
int t, a, b;
void solve() {
    cin >> a >> b;
    if (b < a) swap(a, b);
    if (a <= 23 && b <= 59) {
        if (a <= 9) cout << 0;
        cout << a << ':';
        if (b <= 9) cout << 0;
        cout << b << '\n';
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